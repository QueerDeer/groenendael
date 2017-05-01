QT += core
QT -= gui

LIBS += -lgrpc++ -lgrpc -lgrpc++_reflection -L/usr/local/lib -lprotobuf

TARGET = VT_PROTO_SER
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    test.pb.cc

HEADERS += \
    test.pb.h

