#include "tcpprotoclient.h"
#include <QTimer>
#include <QTime>

tcpprotoclient::tcpprotoclient(QObject *parent) : QObject(parent)
{
    m_pTcpSocket = new QTcpSocket(this);
    m_pTcpSocket->connectToHost("localhost", 6000);

    connect(m_pTcpSocket, SIGNAL(connected()), SLOT(slotConnected()));
    connect(m_pTcpSocket, SIGNAL(readyRead()), SLOT(slotReadyRead()));

    test::test_line src_line;
    src_line.set_uid(21);
    src_line.set_line("Hi, server, it's proto-line, long-long-long-long-long-long-long-long-long-long.");
    src_line.SerializeToString(&msg);
    }

void tcpprotoclient::slotReadyRead()
{
    QByteArray array = m_pTcpSocket->readAll();
    std::cout << array.data() << std::endl;
}


void tcpprotoclient::slotConnected()
{
    std::cout << "Received the connected() signal" << std::endl;

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(slotSendToServer()));
    timer->setInterval(2000);
    timer->start();
}

void tcpprotoclient::slotSendToServer()
{
    std::cout << "send proto-line" << std::endl;
    std::cout << msg << "encoded string" << std::endl;
    m_pTcpSocket->write(&msg[0u]);
}
