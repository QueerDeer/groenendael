QT += core network
QT -= gui

LIBS += -lthrift

TARGET = T_THRIFT_API
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    gen-cpp/test_constants.cpp \
    gen-cpp/test_types.cpp

HEADERS += \
    gen-cpp/test_constants.h \
    gen-cpp/test_types.h
