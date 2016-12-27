#include "mqthread.h"

#include <QtNetwork>

using namespace std;
using namespace MQ;

MQThread::MQThread(qintptr _socket, QByteArray& qba)
    :socket_descriptor{_socket}, byte_array{qba}
{

}

void MQThread::run()
{
    QTcpSocket *client_socket = new QTcpSocket();
    client_socket->setSocketDescriptor(socket_descriptor);
    int n = client_socket->write(byte_array);
    qDebug() << n;
    qDebug() << client_socket->state();
    client_socket->disconnectFromHost();
}
