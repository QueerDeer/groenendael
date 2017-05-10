QT += core network
QT -= gui

INCLUDEPATH += usr/local/include
INCLUDEPATH += usr/include
LIBS += -L"usr/local/lib" -l avrocpp

TARGET = T_AVRO_API
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp

HEADERS += \
    test.hh

