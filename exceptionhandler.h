#ifndef EXCEPTIONHANDLER_H
#define EXCEPTIONHANDLER_H

#include <string>

using namespace std;

namespace MQ
{
    class ExceptionHandler
    {
    public:
        ExceptionHandler();
        ~ExceptionHandler();
        void handleError(string message);
    };
}

#endif // EXCEPTIONHANDLER_H
