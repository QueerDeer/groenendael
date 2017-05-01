#ifndef TCPAVROSERVER_H
#define TCPAVROSERVER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <iostream>
#include <fstream>
#include "avro/ValidSchema.hh"
#include "avro/Compiler.hh"
#include "avro/Writer.hh"

class tcpavroserver : public QObject
{
    Q_OBJECT
public:
    explicit tcpavroserver(QObject *parent = 0);
    avro::ValidSchema testSchema;

public slots:
    void slotNewConnection();
    void slotServerRead();
    void slotClientDisconnected();

private:
    QTcpServer * mTcpServer;
    QTcpSocket * mTcpSocket;
};

#endif // TCPAVROSERVER_H
