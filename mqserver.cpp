#include "mqserver.h"
#include <QtNetwork/QtNetwork>
#include <QtNetwork/QTcpServer>
#include <exception>
#include "exceptionhandler.h"
#include <vector>

using namespace MQ;

MQServer::MQServer(QObject* parent, Logger* _logger)
    :QTcpServer(parent), logger{_logger}
{
    _exception_handler = ExceptionHandler{};
    startServer();
}

MQServer::~MQServer()
{

}

void MQServer::startServer() throw(exception)
{
    logger->log("Setting up server");
    try{
        listen(QHostAddress::Any, 0);

        if(isListening()){
            throw exception();
        }
    } catch (exception& ex){
        _exception_handler.handleError(errorString().toStdString());
    }
    broadcast(QByteArray::number(serverPort()));
    logger->log("Server was setup");
}

void MQServer::incomingConnection(qintptr socketDescriptor)
{
    logger->log("New player connected");
    QTcpSocket *clientConnection = new QTcpSocket();
    clientConnection->setSocketDescriptor(socketDescriptor);
    QObject::connect(clientConnection, &QAbstractSocket::disconnected, clientConnection, &QObject::deleteLater);
    _clients.push_back(clientConnection);
}

QString MQServer::getIP() const
{
    QHostAddress IP = serverAddress();
    return IP.toString();
}

quint16 MQServer::getPort() const
{
    return serverPort();
}

void MQServer::broadcast(QByteArray const & arr_byte)
{
    try{
    QUdpSocket udp_sck{};
    quint16 log = udp_sck.writeDatagram(arr_byte, QHostAddress::Broadcast, 45454);
    if(log == 0)
        throw exception();
    udp_sck.close();
    logger->log("Broadcasting message: " + arr_byte.toStdString());
    } catch(exception & ex){
        broadcast(arr_byte);
    }
}

int MQServer::getNumberClients() const
{
    return (int) (_clients.size());
}
