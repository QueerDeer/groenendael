QT += core
QT -= gui

INCLUDEPATH += usr/local/include
INCLUDEPATH += usr/include
LIBS += -L"usr/local/lib" -l avrocpp

TARGET = VT_AVRO_SER
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp

HEADERS += \
    test.hh

