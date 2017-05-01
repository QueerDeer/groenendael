QT += core network
QT -= gui

TARGET = QJSONServer
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    tcpjsonserver.cpp

HEADERS += \
    tcpjsonserver.h

DISTFILES += \
    test.json

