#ifndef MQSERVER_H
#define MQSERVER_H

#include <vector>
#include <QtNetwork/QtNetwork>
#include <QtNetwork/QTcpServer>
#include "exceptionhandler.h"
#include "logger.h"

namespace MQ
{
    class MQServer : public QTcpServer
    {
    public:
        MQServer(QObject* parent, Logger* _logger);
        ~MQServer();
        QString getIP() const;
        quint16 getPort() const;
        int getNumberClients() const;
    private:
        void startServer() throw(exception);
        void broadcast(QByteArray const & arr_byte);
        void incomingConnection(qintptr socketDescriptor);

        vector<QTcpSocket*> _clients;
        ExceptionHandler _exception_handler;
        Logger* logger;
    };
}
#endif // MQSERVER_H
