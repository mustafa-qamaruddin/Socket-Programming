#include <string>
#include <sstream>
#include <QDataStream>
#include <QObject>

#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "mqserver.h"
#include "logger.h"
#include "mqclient.h"
#include "mqgame.h"
#include "Views/Headers/mqrender.h"

using namespace MQ;
using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QLabel* temp = ui->label_console;
    logger = new Logger{temp};
    logger->log("System Initialized");

    listenToBroadcast();
    mq_thread_pl = new QThreadPool(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    server = new MQServer(this, logger);
    QString ip = server->getIP();
    quint16 port = server->getPort();
    ui->label_server_ip->setText(ip);
    ui->label_server_port->setText(QString::number(port));

    connect(server, SIGNAL(newConnection()), this, SLOT(updatePlayersCounter()));
}

void MainWindow::listenToBroadcast()
{
    logger->log("Listening to broadcast");
    udpSocket = new QUdpSocket();
    udpSocket->bind(45454, QUdpSocket::ShareAddress);

    connect(udpSocket, SIGNAL(readyRead()), this, SLOT(onServerCreatedBroadcast()));
}

void MainWindow::onServerCreatedBroadcast()
{
    while (udpSocket->hasPendingDatagrams()) {
        QByteArray datagram;
        datagram.resize(udpSocket->pendingDatagramSize());
        udpSocket->readDatagram(datagram.data(), datagram.size());

        stringstream ss;
        ss << "Received datagram: " << datagram.data();
        logger->log(ss.str());

        ui->comboBox_servers->addItem(datagram.data(), datagram.data());
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    int  selected = ui->comboBox_servers->currentData().toInt();
    MQClient client{logger, selected};
    connect(client.tcp_socket, SIGNAL(readyRead()), this, SLOT(handleResponse()));
}

void MainWindow::updatePlayersCounter()
{
    ui->lcdNumber_players->display(server->getNumberClients());
}

void MainWindow::on_pushButton_3_clicked()
{
    mqgame = new MQGame(server->getNumberClients());
    mqrender = new MQRender(mqgame->grid, this);
    mqrender->show();
}

void MainWindow::on_pushButton_4_clicked()
{
    // send grid to clients
    QFile mq_file("shared_grid.dat");
    if(!mq_file.open(QIODevice::WriteOnly))
    {
        logger->log("Save Grid Failed");
        return;
    }
    QDataStream qds(&mq_file);
    qds.setVersion(QDataStream::Qt_DefaultCompiledVersion);
    qds << *(mqrender->pix_map);
    mq_file.close();

    QByteArray block;
    block.append(1);
    qDebug() << block;
    server->sendQDataStream(block);
}

void MainWindow::handleResponse()
{
    logger->log("Handling Server Response");
    QFile mq_file{"shared_grid.dat"};
    if( !mq_file.open( QIODevice::ReadOnly ) )
        return;
    QDataStream qds{&mq_file};
    qds.setVersion(QDataStream::Qt_DefaultCompiledVersion);
    QPixmap qpm;
    qds >> qpm;
    mq_file.close();
    ui->label_5->setPixmap(qpm);
}
