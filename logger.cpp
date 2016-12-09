#include "logger.h"
#include <string>
#include <QString>

using namespace std;
using namespace MQ;

Logger::Logger()
{

}

Logger::Logger(QLabel* _qlabel)
    :console{_qlabel}
{

}

Logger::Logger(const Logger &obj)
{
    console = obj.console;
}

Logger::~Logger()
{

}

void Logger::log(string message)
{
    QString temp = console->text();
    temp.append(QString::fromStdString(message));
    temp.append("\r\n");
    console->setText(temp);
}
