#include "tcpjsonclient.h"
#include <QTimer>
#include <QTime>

tcpjsonclient::tcpjsonclient(QObject *parent) : QObject(parent)
{
    m_pTcpSocket = new QTcpSocket(this);
    m_pTcpSocket->connectToHost("localhost", 6000);

    connect(m_pTcpSocket, SIGNAL(connected()), SLOT(slotConnected()));
    connect(m_pTcpSocket, SIGNAL(readyRead()), SLOT(slotReadyRead()));

    QFile file;
    file.setFileName("test.json");
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QString str = file.readAll();
    file.close();

    doc = QJsonDocument::fromJson(str.toUtf8());
    std::cout << doc.toJson().data() << " ok, json-doc was checked" << std::endl;
    //QJsonObject obj = doc.object();
}

void tcpjsonclient::slotReadyRead()
{
    QByteArray array = m_pTcpSocket->readAll();
    std::cout << array.data() << std::endl;
}


void tcpjsonclient::slotConnected()
{
    std::cout << "Received the connected() signal" << std::endl;

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(slotSendToServer()));
    timer->setInterval(4000);
    timer->start();
}

void tcpjsonclient::slotSendToServer()
{


    std::cout << "send json-line" << std::endl;
    m_pTcpSocket->write(doc.toJson());
}
