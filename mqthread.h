#ifndef MQTHREAD_H
#define MQTHREAD_H

#include <QRunnable>
#include <QThreadPool>
#include <QtNetwork>
#include <QDataStream>
#include <QTcpSocket>

namespace MQ
{
    class MQThread : public QRunnable
    {
    public:
        MQThread(qintptr _socket, QByteArray& qba);
        virtual void run();
    private:
        qintptr socket_descriptor;
        QByteArray byte_array;
    };
}

#endif // MQTHREAD_H
