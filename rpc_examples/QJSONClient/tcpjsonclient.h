#ifndef TCPJSONCLIENT_H
#define TCPJSONCLIENT_H

#include <QObject>
#include <QTcpSocket>
#include <iostream>
#include <QJsonDocument>
#include <QJsonObject>
#include <QFile>

class tcpjsonclient : public QObject
{
    Q_OBJECT
public:
    explicit tcpjsonclient(QObject *parent = 0);
     QJsonDocument doc;

private:
    QTcpSocket* m_pTcpSocket;
    quint16     m_nNextBlockSize;

signals:

private slots:
    void slotReadyRead();
    void slotSendToServer();
    void slotConnected( );
};

#endif // TCPJSONCLIENT_H
