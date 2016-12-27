#include "mqserver.h"
#include "exceptionhandler.h"
#include "mqthread.h"

#include <exception>
#include <vector>
#include <sstream>

#include <QtNetwork/QtNetwork>
#include <QtNetwork/QTcpServer>


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
    _clients.push_back(socketDescriptor);
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

void MQServer::sendQDataStream(QByteArray& qba)
{
    logger->log("Spawning Threads");
    for(int i = 0; i < getNumberClients(); i++)
    {
        QTcpSocket *client_socket = new QTcpSocket();
        client_socket->setSocketDescriptor(_clients[i]);
        int n = client_socket->write(qba);
        qDebug() << n;
        client_socket->close();
        stringstream ss;
        ss << "Client #" << i << " was notified";
        logger->log(ss.str());
    }
}
