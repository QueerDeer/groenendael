QT += core network
QT -= gui

INCLUDEPATH += usr/local/include
INCLUDEPATH += usr/include
LIBS += -L"usr/local/lib" -l avrocpp

TARGET = QAvroServer
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    tcpavroserver.cpp

HEADERS += \
    tcpavroserver.h \
    test.hh

DISTFILES += \
    test.json


