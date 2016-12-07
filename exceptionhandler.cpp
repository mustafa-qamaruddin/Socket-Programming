#include "exceptionhandler.h"
#include <QMessageBox>

using namespace MQ;

ExceptionHandler::ExceptionHandler()
{

}

ExceptionHandler::~ExceptionHandler()
{

}

void ExceptionHandler::handleServerSetup(string message)
{
    QMessageBox msg_box;
    msg_box.critical(0, "Error", QString::fromStdString(message));
    msg_box.show();
}
