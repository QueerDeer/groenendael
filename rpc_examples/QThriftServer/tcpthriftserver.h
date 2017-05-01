#ifndef TCPTHRIFTSERVER_H
#define TCPTHRIFTSERVER_H

#include <QObject>
#include <QTcpServer>
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

class tcpthriftserver : public QObject
{
    Q_OBJECT
public:
    explicit tcpthriftserver(QObject *parent = 0);

public slots:
    void slotNewConnection();
    void slotServerRead();
    void slotClientDisconnected();

private:
    QTcpServer * mTcpServer;
    QTcpSocket * mTcpSocket;
};

#endif // TCPTHRIFTSERVER_H
