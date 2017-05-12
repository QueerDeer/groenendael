QT += core
QT -= gui

TARGET = FullgRPCClient
CONFIG += c++11
CONFIG += console
CONFIG -= app_bundle

LIBS += -lgrpc++ -lgrpc -lgrpc++_reflection -L/usr/local/lib -lprotobuf

TEMPLATE = app

SOURCES += main.cpp \
    test.grpc.pb.cc \
    test.pb.cc \
    grpcclient.cpp

HEADERS += \
    test.grpc.pb.h \
    test.pb.h \
    grpcclient.h

