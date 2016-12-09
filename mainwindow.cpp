#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mqserver.h"
#include <string>
#include <sstream>
#include "logger.h"
#include "mqclient.h"

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
    MQServer server{logger};
    QString ip = server.getIP();
    quint16 port = server.getPort();
    ui->label_server_ip->setText(ip);
    ui->label_server_port->setText(QString::number(port));
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
    }
}
