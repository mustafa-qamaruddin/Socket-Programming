#include "mqitem.h"

using namespace std;
using namespace MQ;

MQItem::MQItem(int _r1, int _c1, int _r2, int _c2, int _l)
    :r1{_r1}, c1{_c1}, r2{_r2}, c2{_c2}, l{_l}
{

}

MQItem::~MQItem()
{

}

bool MQItem::overlap(MQItem const & lhs) const
{
    return( (c1 == lhs.c1) && ((r2 > lhs.r1) || (r1 < lhs.r2 ) ) );
}
