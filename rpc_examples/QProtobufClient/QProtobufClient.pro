QT += core network
QT -= gui

LIBS += -lgrpc++ -lgrpc -lgrpc++_reflection -L/usr/local/lib -lprotobuf

TARGET = QProtobufClient
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    tcpprotoclient.cpp \
    test.pb.cc

HEADERS += \
    tcpprotoclient.h \
    test.pb.h

DISTFILES += \
    test.proto

