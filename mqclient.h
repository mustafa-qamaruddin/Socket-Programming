#ifndef MQCLIENT_H
#define MQCLIENT_H

#include <QtNetwork>
#include <QRunnable>
#include <QWidget>
#include "logger.h"

namespace MQ {
    class MQClient: public QObject
    {
        Q_OBJECT
    public:
        MQClient(Logger* _logger, int _port);
        ~MQClient();
        void run();

        Logger* logger;
        QTcpSocket* tcp_socket;
        int port;
    public slots:
        void handleResponse();
    private:

    };
}
#endif // MQCLIENT_H
