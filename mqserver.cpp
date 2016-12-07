#include "mqserver.h"
#include <QtNetwork/QtNetwork>
#include <QtNetwork/QTcpServer>
#include <exception>
#include "exceptionhandler.h"

using namespace MQ;

MQServer::MQServer()
{
    _exception_handler = ExceptionHandler{};
    setupServer();
}

MQServer::~MQServer()
{

}

void MQServer::setupServer()
{
    _server = new QTcpServer();
    try{
        if(_server->isListening()){
            throw "Server was not setup";
        }
    } catch (exception& ex){
        _exception_handler.handleServerSetup(ex.what());
    }
}

void MQServer::spawnClients()
{

}

void MQServer::handleClient()
{

}
