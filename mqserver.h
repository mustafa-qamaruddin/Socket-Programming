#ifndef MQSERVER_H
#define MQSERVER_H

#include <vector>
#include <QtNetwork/QtNetwork>
#include <QtNetwork/QTcpServer>
#include "exceptionhandler.h"
#include "logger.h"

namespace MQ
{
    class MQServer
    {
    public:
        MQServer(Logger* _logger);
        ~MQServer();
        QString getIP() const;
        quint16 getPort() const;
    private:
        void setupServer() throw(exception);
        void spawnClients();
        void handleClient();
        void broadcast(QByteArray const & arr_byte);
        QTcpServer* _server;
        vector<QTcpSocket> _clients;
        ExceptionHandler _exception_handler;
        Logger* logger;
    };
}
#endif // MQSERVER_H
