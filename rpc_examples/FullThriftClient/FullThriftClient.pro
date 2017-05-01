QT += core
QT -= gui

TARGET = FullThriftClient
CONFIG += console
CONFIG -= app_bundle

LIBS += -lthrift

TEMPLATE = app

SOURCES += main.cpp \
    fullthriftclient.cpp \
    gen-cpp/MessageManager.cpp \
    gen-cpp/test_constants.cpp \
    gen-cpp/test_types.cpp

HEADERS += \
    fullthriftclient.h \
    gen-cpp/MessageManager.h \
    gen-cpp/test_constants.h \
    gen-cpp/test_types.h

DISTFILES += \
    test.thrift

