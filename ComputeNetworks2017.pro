#-------------------------------------------------
#
# Project created by QtCreator 2016-12-05T16:59:19
#
#-------------------------------------------------

QT       += core gui
QT       += network widgets


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ComputeNetworks2017
TEMPLATE = app


HEADERS  += mainwindow.h \
    mqserver.h \
    exceptionhandler.h \
    logger.h \
    mqclient.h

SOURCES += main.cpp\
        mainwindow.cpp \
    mqserver.cpp \
    exceptionhandler.cpp \
    logger.cpp \
    mqclient.cpp

FORMS    += mainwindow.ui
