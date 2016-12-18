#ifndef MQLADDER_H
#define MQLADDER_H

#include "mqitem.h"

namespace MQ
{
    class MQLadder: public MQItem
    {
    public:
        MQLadder(int _r1, int _c1, int _r2, int _c2, int _length);
        ~MQLadder();
    };
}
#endif // MQLADDER_H
