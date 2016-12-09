#ifndef LOGGER_H
#define LOGGER_H

#include <string>
#include <QLabel>

using namespace std;

namespace MQ
{
    class Logger
    {
    public:
        Logger();
        Logger(QLabel* _qlabel);
        Logger(const Logger& obj);
        ~Logger();
        void log(string message);
        QLabel* console;
    };
}
#endif // LOGGER_H
