#ifndef MQCLIENT_H
#define MQCLIENT_H

#include <QtNetwork>
#include <QWidget>
#include "logger.h"

namespace MQ {
    class MQClient
    {
    public:
        MQClient(Logger* _logger);
        ~MQClient();
    private:
        Logger* logger;
    };
}
#endif // MQCLIENT_H
