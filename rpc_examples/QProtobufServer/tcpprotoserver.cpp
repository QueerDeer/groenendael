#include "tcpprotoserver.h"

tcpprotoserver::tcpprotoserver(QObject *parent) : QObject(parent)
{
    mTcpServer = new QTcpServer(this);
    mTcpServer->listen(QHostAddress::Any, 6000);
    std::cout << "server was started" << std::endl;
    connect(mTcpServer, &QTcpServer::newConnection, this, &tcpprotoserver::slotNewConnection);
}

void tcpprotoserver::slotNewConnection()
{
    mTcpSocket = mTcpServer->nextPendingConnection();
    std::cout << "client was connected" << std::endl;

    connect(mTcpSocket, &QTcpSocket::readyRead, this, &tcpprotoserver::slotServerRead);
    connect(mTcpSocket, &QTcpSocket::disconnected, this, &tcpprotoserver::slotClientDisconnected);

    mTcpSocket->write("Hi, client");
}

void tcpprotoserver::slotServerRead()
{
        QByteArray array = mTcpSocket->readAll();
        std::string msg = array.data();

        std::cout << msg << " encoded string" << std::endl;

        test::test_line dst_line;
        dst_line.ParseFromString(msg);

        dst_line.PrintDebugString();
        std::cout << "decoded string" << std::endl;

        mTcpSocket->write("got proto-line");
}

void tcpprotoserver::slotClientDisconnected()
{
    mTcpSocket->close();
}
