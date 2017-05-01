QT += core network
QT -= gui

TARGET = QJSONClient
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    tcpjsonclient.cpp

HEADERS += \
    tcpjsonclient.h

DISTFILES += \
    test.json

