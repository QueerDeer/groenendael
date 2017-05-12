QT += core
QT -= gui

TARGET = FullThriftServer
CONFIG += console
CONFIG -= app_bundle

LIBS += -lthrift

TEMPLATE = app

SOURCES += main.cpp \
    fullthriftserver.cpp \
    gen-cpp/MessageManager.cpp \
    gen-cpp/test_constants.cpp \
    gen-cpp/test_types.cpp

HEADERS += \
    fullthriftserver.h \
    gen-cpp/MessageManager.h \
    gen-cpp/test_constants.h \
    gen-cpp/test_types.h

DISTFILES += \
    test.thrift

