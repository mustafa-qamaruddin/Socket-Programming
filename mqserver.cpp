#include "mqserver.h"
#include <QtNetwork/QtNetwork>
#include <QtNetwork/QTcpServer>
#include <exception>
#include "exceptionhandler.h"

using namespace MQ;

MQServer::MQServer(Logger* _logger)
    :logger{_logger}
{
    _exception_handler = ExceptionHandler{};
    setupServer();
    broadcast(QByteArray::number(_server->serverPort()));
}

MQServer::~MQServer()
{

}

void MQServer::setupServer() throw(exception)
{
    logger->log("Setting up server");
    try{
        _server = new QTcpServer();
        _server->listen(QHostAddress::Any, 0);

        if(!_server->isListening()){
            throw exception();
        }
    } catch (exception& ex){
        _exception_handler.handleError(_server->errorString().toStdString());
    }
    logger->log("Server was setup");
}

void MQServer::spawnClients()
{

}

void MQServer::handleClient()
{

}

QString MQServer::getIP() const
{
    QHostAddress IP = _server->serverAddress();
    return IP.toString();
}

quint16 MQServer::getPort() const
{
    return _server->serverPort();
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
