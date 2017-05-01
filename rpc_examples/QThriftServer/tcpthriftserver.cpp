#include "tcpthriftserver.h"

tcpthriftserver::tcpthriftserver(QObject *parent) : QObject(parent)
{
    mTcpServer = new QTcpServer(this);
    mTcpServer->listen(QHostAddress::Any, 6000);
    std::cout << "server was started" << std::endl;
    connect(mTcpServer, &QTcpServer::newConnection, this, &tcpthriftserver::slotNewConnection);
}

void tcpthriftserver::slotNewConnection()
{
    mTcpSocket = mTcpServer->nextPendingConnection();

    connect(mTcpSocket, &QTcpSocket::readyRead, this, &tcpthriftserver::slotServerRead);
    connect(mTcpSocket, &QTcpSocket::disconnected, this, &tcpthriftserver::slotClientDisconnected);
    std::cout << "client was connected" << std::endl;
    mTcpSocket->write("Hi, client");
}

void tcpthriftserver::slotServerRead()
{
    QByteArray array = mTcpSocket->readAll();
    std::string serialized(array.constData(), array.length());
    std::cout << serialized << "serialized format" << std::endl;

    shared_ptr<TMemoryBuffer> strBuffer2(new TMemoryBuffer());
    shared_ptr<TBinaryProtocol> binaryProtcol2(new TBinaryProtocol(strBuffer2));
    strBuffer2->resetBuffer((uint8_t*)serialized.data(), static_cast<uint32_t>(serialized.length()));
    message msg2;
    msg2.read(binaryProtcol2.get());
    const std::string result(apache::thrift::ThriftDebugString(msg2));
    std::cout << result << " on-server deserialized view" << std::endl;


        mTcpSocket->write("got thrift-binary");
}

void tcpthriftserver::slotClientDisconnected()
{
    mTcpSocket->close();
}
