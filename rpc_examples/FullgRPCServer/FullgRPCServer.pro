QT += core
QT -= gui

TARGET = FullgRPCServer
CONFIG += c++11
CONFIG += console
CONFIG -= app_bundle

LIBS += -lgrpc++ -lgrpc -lgrpc++_reflection -L/usr/local/lib -lprotobuf 

TEMPLATE = app

SOURCES += main.cpp \
    test.grpc.pb.cc \
    test.pb.cc \
    grpcserver.cpp

DISTFILES += \
    test.proto

HEADERS += \
    test.grpc.pb.h \
    test.pb.h \
    grpcserver.h

DEFINES += 
