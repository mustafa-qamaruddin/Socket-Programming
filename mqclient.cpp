#include "mqclient.h"
#include <QtNetwork>
#include <QIODevice>
#include <QDataStream>
#include <QPixmap>
#include <QRunnable>

using namespace std;
using namespace MQ;

MQClient::MQClient(Logger* _logger, int _port)
    :logger{_logger}, port{_port}
{
    tcp_socket = new QTcpSocket();
    logger->log("Client connected");
    tcp_socket->connectToHost(QHostAddress::LocalHost, port);
}

MQClient::~MQClient()
{

}

void MQClient::run()
{
}

void MQClient::handleResponse()
{
    logger->log("Reading Server Response");
    QFile  mq_file{"shared_grid.dat"};
    if(!mq_file.open(QIODevice::ReadOnly))
    {
        logger->log("Grid Could Not Be Loaded");
        return;
    }
    QDataStream qds{&mq_file};
    qds.setVersion(QDataStream::Qt_DefaultCompiledVersion);
    QPixmap qpm;
    qds >> qpm;
    qDebug() << qpm;
}
