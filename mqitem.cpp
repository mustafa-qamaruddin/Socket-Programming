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
    return( (r1 != lhs.r1) || (c2 < lhs.c1) || (c1 > lhs.c2 ) );
}
