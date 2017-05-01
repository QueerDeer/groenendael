#ifndef TCPJSONSERVER_H
#define TCPJSONSERVER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <iostream>
#include <QJsonDocument>
#include <QJsonObject>

class tcpjsonserver : public QObject
{
    Q_OBJECT
public:
    explicit tcpjsonserver(QObject *parent = 0);

public slots:
    void slotNewConnection();
    void slotServerRead();
    void slotClientDisconnected();

private:
    QTcpServer * mTcpServer;
    QTcpSocket * mTcpSocket;
};

#endif // TCPJSONSERVER_H
