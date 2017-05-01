QT += core network
QT -= gui

LIBS += -lgrpc++ -lgrpc -lgrpc++_reflection -L/usr/local/lib -lprotobuf

TARGET = QProtobufServer
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    tcpprotoserver.cpp \
    test.pb.cc

HEADERS += \
    tcpprotoserver.h \
    test.pb.h

DISTFILES += \
    test.proto

