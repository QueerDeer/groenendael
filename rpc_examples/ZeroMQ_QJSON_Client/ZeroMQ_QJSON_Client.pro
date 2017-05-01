QT += core
QT -= gui

#include(/home/groenendael/ZeroMQ/czmq/bindings/qt/src/qczmq.pri)
#LIBS += /home/groenendael/ZeroMQ/zeromq-4.1.6/src
LIBS += -lzmq

TARGET = ZeroMQ_QJSON_Client
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp

