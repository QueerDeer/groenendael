QT += core network
QT -= gui

LIBS += -lthrift

TARGET = QThriftfServer
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    tcpthriftserver.cpp \
    gen-cpp/test_constants.cpp \
    gen-cpp/test_types.cpp

HEADERS += \
    tcpthriftserver.h \
    gen-cpp/test_constants.h \
    gen-cpp/test_types.h

DISTFILES += \
    test.thrift

