#ifndef MQSERVER_H
#define MQSERVER_H

#include <vector>
#include <QtNetwork/QtNetwork>
#include <QtNetwork/QTcpServer>
#include <QtGlobal>
#include <QDataStream>
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
        void sendQDataStream(QByteArray& qba);
    private slots:
        void deleteThread();
    private:
        void startServer() throw(exception);
        void broadcast(QByteArray const & arr_byte);
        void incomingConnection(qintptr socketDescriptor);

        vector<qintptr> _clients;
        ExceptionHandler _exception_handler;
        Logger* logger;
    };
}
#endif // MQSERVER_H
