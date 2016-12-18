#-------------------------------------------------
#
# Project created by QtCreator 2016-12-05T16:59:19
#
#-------------------------------------------------

QT       += core gui
QT       += network widgets testlib


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ComputeNetworks2017
TEMPLATE = app

    HEADERS  += mainwindow.h \
        mqserver.h \
        exceptionhandler.h \
        logger.h \
        mqclient.h \
        mqgame.h \
        mqsnake.h \
        mqladder.h \
        mqposition.h \
        mqgrid.h \
        mqutilities.h \
        Tests/Headers/mqgridut.h \
    mqitem.h

    SOURCES += main.cpp\
            mainwindow.cpp \
        mqserver.cpp \
        exceptionhandler.cpp \
        logger.cpp \
        mqclient.cpp \
        mqgrid.cpp \
        Tests/Sources/mqgridut.cpp \
    mqutilities.cpp \
    mqitem.cpp

    FORMS    += mainwindow.ui

SOURCES += \
    mqladder.cpp \
    mqsnake.cpp
