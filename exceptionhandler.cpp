#include "exceptionhandler.h"

#include <QMessageBox>
#include <QString>

using namespace MQ;

ExceptionHandler::ExceptionHandler()
{

}

ExceptionHandler::~ExceptionHandler()
{

}

void ExceptionHandler::handleError(string message)
{
    QMessageBox msg_box;
    msg_box.critical(0, "Error", QString::fromStdString(message));
    msg_box.show();
}
