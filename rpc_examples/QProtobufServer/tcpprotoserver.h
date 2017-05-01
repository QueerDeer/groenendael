#ifndef TCPPROTOSERVER_H
#define TCPPROTOSERVER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <iostream>
#include "test.pb.h"

class tcpprotoserver : public QObject
{
    Q_OBJECT
public:
    explicit tcpprotoserver(QObject *parent = 0);

public slots:
    void slotNewConnection();
    void slotServerRead();
    void slotClientDisconnected();

private:
    QTcpServer * mTcpServer;
    QTcpSocket * mTcpSocket;
};

#endif // TCPPROTOSERVER_H
