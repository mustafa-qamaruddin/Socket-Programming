#include "mqclient.h"
#include <QtNetwork>
#include <QtWidgets>

using namespace std;
using namespace MQ;

MQClient::MQClient(Logger* _logger, int port)
    :logger{_logger}
{
    tcp_socket = new QTcpSocket();
    tcp_socket->connectToHost(QHostAddress::LocalHost, port);
    logger->log("Client created");
}

MQClient::~MQClient()
{

}
