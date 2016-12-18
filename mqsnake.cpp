#include "mqsnake.h"
#include "mqitem.h"

using namespace std;
using namespace MQ;

MQSnake::MQSnake(int _r1, int _c1, int _r2, int _c2, int _l)
    :MQItem{_r1, _c1, _r2, _c2, _l}
{

}

MQSnake::~MQSnake()
{

}
