QT += core network
QT -= gui

LIBS += -lthrift

TARGET = QThriftClient
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    tcpthriftclient.cpp \
    gen-cpp/test_constants.cpp \
    gen-cpp/test_types.cpp

HEADERS += \
    tcpthriftclient.h \
    gen-cpp/test_constants.h \
    gen-cpp/test_types.h

DISTFILES += \
    test.thrift

