#ifndef TCPAVROCLIENT_H
#define TCPAVROCLIENT_H

#include <QObject>
#include <QTcpSocket>
#include <iostream>
#include <fstream>
#include "avro/ValidSchema.hh"
#include "avro/Compiler.hh"
#include "avro/Reader.hh"

class tcpavroclient : public QObject
{
    Q_OBJECT
public:
    explicit tcpavroclient(QObject *parent = 0);
    std::string str;

private:
    QTcpSocket* m_pTcpSocket;
    quint16     m_nNextBlockSize;

signals:

private slots:
    void slotReadyRead();
    void slotSendToServer();
    void slotConnected( );
};

#endif // TCPAVROCLIENT_H
