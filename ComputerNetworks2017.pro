#-------------------------------------------------
#
# Project created by QtCreator 2016-12-20T06:37:55
#
#-------------------------------------------------

QT       += core gui network testlib widgets
CONFIG += c++11
QMAKE_CXXFLAGS += -std=c++0x

TARGET = ComputerNetworks2017
TEMPLATE = app

SOURCES += main.cpp\
        mainwindow.cpp \
    exceptionhandler.cpp \
    logger.cpp \
    mqclient.cpp \
    mqgame.cpp \
    mqgrid.cpp \
    mqitem.cpp \
    mqladder.cpp \
    mqserver.cpp \
    mqsnake.cpp \
    mqutilities.cpp \
    Tests/Sources/mqgridut.cpp \
    Views/Sources/mqrender.cpp

HEADERS  += mainwindow.h \
    exceptionhandler.h \
    logger.h \
    mqclient.h \
    mqgame.h \
    mqgrid.h \
    mqitem.h \
    mqladder.h \
    mqposition.h \
    mqserver.h \
    mqsnake.h \
    mqutilities.h \
    ui_mainwindow.h \
    Tests/Headers/mqgridut.h \
    Views/Headers/mqrender.h

FORMS += \
    mainwindow.ui
