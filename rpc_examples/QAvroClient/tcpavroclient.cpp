#include "tcpavroclient.h"
#include "test.hh"
#include <QTimer>
#include <QTime>

tcpavroclient::tcpavroclient(QObject *parent) : QObject(parent)
{
    m_pTcpSocket = new QTcpSocket(this);
    m_pTcpSocket->connectToHost("localhost", 6000);

    connect(m_pTcpSocket, SIGNAL(connected()), SLOT(slotConnected()));
    connect(m_pTcpSocket, SIGNAL(readyRead()), SLOT(slotReadyRead()));

    std::ifstream input("test.json");
    avro::ValidSchema testSchema;
    avro::compileJsonSchema(input, testSchema);

    std::auto_ptr<avro::OutputStream> out = avro::memoryOutputStream();
    avro::EncoderPtr e = avro::jsonEncoder(testSchema);
    e->init(*out);
    c::test message_out;
    message_out.uid = 21.;
    message_out.line = "Hi, it's json-encoded(for example) line by aaaaaaaaaaaaaaaaaaaaaaaaaaaavro, horray.";
    avro::encode(*e, message_out);

    std::auto_ptr<avro::InputStream> in = avro::memoryInputStream(*out);
    avro::StreamReader* reader = new avro::StreamReader(*in);
    while (reader->hasMore())
    {
        uint8_t c = reader->read();
        str.push_back(c);
    }
    std::cout << str << "encoded" << std::endl;
}

void tcpavroclient::slotReadyRead()
{
    QByteArray array = m_pTcpSocket->readAll();
    std::cout << array.data() << std::endl;
}


void tcpavroclient::slotConnected()
{
    std::cout << "Received the connected() signal" << std::endl;

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(slotSendToServer()));
    timer->setInterval(4000);
    timer->start();
}

void tcpavroclient::slotSendToServer()
{
    std::cout << "send avro-line" << std::endl;
    QByteArray byteArray(str.c_str(), str.length());
    m_pTcpSocket->write(byteArray);
}
