#ifndef TCPPROTOCLIENT_H
#define TCPPROTOCLIENT_H

#include <QObject>
#include <QTcpSocket>
#include <iostream>
#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/transport/TBufferTransports.h>
#include <thrift/protocol/TDebugProtocol.h>
#include "gen-cpp/test_types.h"

using namespace boost;
using namespace std;
using namespace apache::thrift;
using apache::thrift::transport::TMemoryBuffer;
using apache::thrift::protocol::TBinaryProtocol;
using apache::thrift::transport::TTransportException;

class tcpthriftclient : public QObject
{
    Q_OBJECT
public:
    explicit tcpthriftclient(QObject *parent = 0);

private:
    QTcpSocket* m_pTcpSocket;
    quint16     m_nNextBlockSize;

signals:

private slots:
    void slotReadyRead();
    void slotSendToServer();
    void slotConnected( );
};

#endif // TCPPROTOCLIENT_H
