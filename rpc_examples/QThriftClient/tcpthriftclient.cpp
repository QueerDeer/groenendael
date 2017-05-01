#include "tcpthriftclient.h"
#include <QTimer>
#include <QTime>

tcpthriftclient::tcpthriftclient(QObject *parent) : QObject(parent)
{
    m_pTcpSocket = new QTcpSocket(this);
    m_pTcpSocket->connectToHost("localhost", 6000);

    connect(m_pTcpSocket, SIGNAL(connected()), SLOT(slotConnected()));
    connect(m_pTcpSocket, SIGNAL(readyRead()), SLOT(slotReadyRead()));

}

void tcpthriftclient::slotReadyRead()
{
    QByteArray array = m_pTcpSocket->readAll();
    std::cout << array.data() << std::endl;
}


void tcpthriftclient::slotConnected()
{
    std::cout << "Received the connected() signal" << std::endl;

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(slotSendToServer()));
    timer->setInterval(2000);
    timer->start();
}

void tcpthriftclient::slotSendToServer()
{
    static std::auto_ptr<message> msg;
    msg.reset(new message);
    msg->uid = 21;
    msg->line = "Hi, server, it,s thrift-line, looooooooooooooooong-loooooooong-looooong-long.";

    boost::shared_ptr<TMemoryBuffer> buffer(new TMemoryBuffer());
    boost::shared_ptr<TBinaryProtocol> proto(new TBinaryProtocol(buffer));

    std::string serialized;
    msg->write(proto.get());
    serialized = buffer->getBufferAsString();

    shared_ptr<TMemoryBuffer> strBuffer2(new TMemoryBuffer());
    shared_ptr<TBinaryProtocol> binaryProtcol2(new TBinaryProtocol(strBuffer2));
    strBuffer2->resetBuffer((uint8_t*)serialized.data(), static_cast<uint32_t>(serialized.length()));
    message msg2;
    msg2.read(binaryProtcol2.get());
    const std::string result(apache::thrift::ThriftDebugString(msg2));
    std::cout << result << "debugging view" << std::endl;

    std::cout << serialized << "serialized view" << std::endl;
    QByteArray byteArray(serialized.c_str(), serialized.length());
    m_pTcpSocket->write(byteArray);
    std::cout << "send binary-line" << std::endl;
}
