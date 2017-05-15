QT += core
QT -= gui

#include(/home/groenendael/ZeroMQ/czmq/bindings/qt/src/qczmq.pri)
#LIBS += /home/groenendael/ZeroMQ/zeromq-4.1.6/src
LIBS += -lzmq
LIBS += -lgrpc++ -lgrpc -lgrpc++_reflection -L/usr/local/lib -lprotobuf

TARGET = ZMQProtoServer
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    test.pb.cc

HEADERS += \
    test.pb.h

