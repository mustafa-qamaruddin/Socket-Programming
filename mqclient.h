#ifndef MQCLIENT_H
#define MQCLIENT_H

#include <QtNetwork>
#include <QWidget>
#include "logger.h"

namespace MQ {
    class MQClient
    {
    public:
        MQClient(Logger* _logger, int port);
        ~MQClient();
    private:
        Logger* logger;
        QTcpSocket* tcp_socket;
    };
}
#endif // MQCLIENT_H
