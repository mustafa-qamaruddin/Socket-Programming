#ifndef MQSERVER_H
#define MQSERVER_H

#include <vector>
#include <QtNetwork/QtNetwork>
#include <QtNetwork/QTcpServer>
#include "exceptionhandler.h"

namespace MQ
{
    class MQServer
    {
    public:
        MQServer();
        ~MQServer();
    private:
        void setupServer();
        void spawnClients();
        void handleClient();
        QTcpServer* _server;
        vector<QTcpSocket> _clients;
        ExceptionHandler _exception_handler;
    };
}
#endif // MQSERVER_H
