#ifndef MQSNAKE_H
#define MQSNAKE_H

#include "mqitem.h"

namespace MQ
{
    class MQSnake : public MQItem
    {
    public:
        MQSnake(int _r1, int _c1, int _r2, int _c2, int _l);
        ~MQSnake();
    };
}
#endif // MQSNAKE_H
