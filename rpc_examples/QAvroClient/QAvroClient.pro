QT += core network
QT -= gui

INCLUDEPATH += usr/local/include
INCLUDEPATH += usr/include
LIBS += -L"usr/local/lib" -l avrocpp

TARGET = QAvroClient
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    tcpavroclient.cpp

HEADERS += \
    tcpavroclient.h \
    test.hh

DISTFILES += \
    test.json


