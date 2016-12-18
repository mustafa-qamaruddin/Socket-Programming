#include "mainwindow.h"
#include <QApplication>

#include <QtTest/QTest>
#include "tests/Headers/mqgridut.h"

int main(int argc, char *argv[])
{
    return QTest::qExec(new MQ::MQGridUT, argc, argv);
//    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();

//    return a.exec();
}
