#ifndef TCPPROTOCLIENT_H
#define TCPPROTOCLIENT_H

#include <QObject>
#include <QTcpSocket>
#include <iostream>
#include "test.pb.h"

class tcpprotoclient : public QObject
{
    Q_OBJECT
public:
    explicit tcpprotoclient(QObject *parent = 0);
    std::string msg;

private:
    QTcpSocket* m_pTcpSocket;
    quint16     m_nNextBlockSize;

signals:

private slots:
    void slotReadyRead();
    void slotSendToServer();
    void slotConnected( );
};

#endif // TCPPROTOCLIENT_H
