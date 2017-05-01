#include "tcpavroserver.h"
#include "test.hh"

tcpavroserver::tcpavroserver(QObject *parent) : QObject(parent)
{
    mTcpServer = new QTcpServer(this);
    mTcpServer->listen(QHostAddress::Any, 6000);
    std::cout << "server was started" << std::endl;
    connect(mTcpServer, &QTcpServer::newConnection, this, &tcpavroserver::slotNewConnection);

    std::ifstream input("test.json");
    avro::compileJsonSchema(input, testSchema);
}

void tcpavroserver::slotNewConnection()
{
    mTcpSocket = mTcpServer->nextPendingConnection();
    std::cout << "client was connected" << std::endl;

    connect(mTcpSocket, &QTcpSocket::readyRead, this, &tcpavroserver::slotServerRead);
    connect(mTcpSocket, &QTcpSocket::disconnected, this, &tcpavroserver::slotClientDisconnected);

    mTcpSocket->write("Hi, client");
}

void tcpavroserver::slotServerRead()
{
    QByteArray array = mTcpSocket->readAll();
    std::string str;
    str.operator =(array.data());

    std::auto_ptr<avro::OutputStream> out = avro::memoryOutputStream();
    avro::StreamWriter* writer = new avro::StreamWriter(*out);
    for (int i = 0; i < str.length(); i++)
    {
        uint8_t c = str[i];
        writer->write(c);
    }

    std::auto_ptr<avro::InputStream> in = avro::memoryInputStream(*out);
    avro::DecoderPtr d = avro::jsonDecoder(testSchema);
    d->init(*in);

    c::test message_in;
    avro::decode(*d, message_in);
    std::cout << ' ' << message_in.uid << " " << message_in.line << "decoded" << std::endl;

    mTcpSocket->write("got avro-line");
}

void tcpavroserver::slotClientDisconnected()
{
    mTcpSocket->close();
}
