#ifndef MQGRIDUT_H
#define MQGRIDUT_H

#include <QtTest/QtTest>
#include "mqgrid.h"

namespace MQ
{
    class MQGridUT: public QObject
    {
        Q_OBJECT
    public:
        MQGridUT();
        ~MQGridUT();
    private slots:
        void testInit_data();
        void testInit();
        void testOverlap_data();
        void testOverlap();
        void testNumItems_data();
        void testNumItems();
    };
}

#endif // MQGRIDUT_H
