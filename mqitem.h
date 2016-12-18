#ifndef MQITEM_H
#define MQITEM_H

namespace MQ {
    class MQItem
    {
    public:
        MQItem(int _r1, int _c1, int _r2, int _c2, int _l);
        ~MQItem();
        bool overlap(MQItem const &lhs) const;

        int r1, c1, r2, c2, l;
    };
}

#endif // MQITEM_H
