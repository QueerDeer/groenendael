#include "tcpjsonserver.h"
#include <QDebug>

tcpjsonserver::tcpjsonserver(QObject *parent) : QObject(parent)
{
    mTcpServer = new QTcpServer(this);
    mTcpServer->listen(QHostAddress::Any, 6000);
    std::cout << "server was started" << std::endl;
    connect(mTcpServer, &QTcpServer::newConnection, this, &tcpjsonserver::slotNewConnection);
}

void tcpjsonserver::slotNewConnection()
{
    mTcpSocket = mTcpServer->nextPendingConnection();
    std::cout << "client was connected" << std::endl;

    connect(mTcpSocket, &QTcpSocket::readyRead, this, &tcpjsonserver::slotServerRead);
    connect(mTcpSocket, &QTcpSocket::disconnected, this, &tcpjsonserver::slotClientDisconnected);

    mTcpSocket->write("Hi, client");
}

void tcpjsonserver::slotServerRead()
{
        QByteArray array = mTcpSocket->readAll();
        //std::cout << array.data() << std::endl;
        QJsonDocument doc (QJsonDocument::fromJson(array));
        std::cout << doc.toJson().data() << " decoded string" << std::endl;
        mTcpSocket->write("got json-line");
}

void tcpjsonserver::slotClientDisconnected()
{
    mTcpSocket->close();
}
