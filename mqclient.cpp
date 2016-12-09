#include "mqclient.h"
#include <QtNetwork>
#include <QtWidgets>

using namespace std;
using namespace MQ;

MQClient::MQClient(Logger* _logger)
    :logger{_logger}
{
    logger->log("Client created");
}

MQClient::~MQClient()
{

}
