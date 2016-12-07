#-------------------------------------------------
#
# Project created by QtCreator 2016-12-05T16:59:19
#
#-------------------------------------------------

QT       += core gui
QT       += network


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ComputeNetworks2017
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    mqserver.cpp \
    exceptionhandler.cpp

HEADERS  += mainwindow.h \
    mqserver.h \
    exceptionhandler.h

FORMS    += mainwindow.ui
