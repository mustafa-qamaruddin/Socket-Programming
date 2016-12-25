#include <string>
#include <sstream>

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

//    connect(server->getServer(), QTcpServer::newConnection, server->getServer(), server->spawnClients);
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
}

void MainWindow::updatePlayersCounter()
{
    ui->lcdNumber_players->display(server->getNumberClients());
}

void MainWindow::on_pushButton_3_clicked()
{
    MQGame g{server->getNumberClients()};
    MQRender* r = new MQRender(g.grid, this);
    r->show();
}
