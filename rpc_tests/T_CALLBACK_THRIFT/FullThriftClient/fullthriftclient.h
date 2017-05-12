#ifndef FULLTHRIFTCLIENT_H
#define FULLTHRIFTCLIENT_H

#include <QObject>
#include <iostream>
#include "gen-cpp/MessageManager.h"
#include <thrift/protocol/TDebugProtocol.h>
#include <thrift/transport/TSocket.h>
#include <thrift/transport/TBufferTransports.h>
#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/protocol/TCompactProtocol.h>
#include <thrift/protocol/TJSONProtocol.h>
#include <fstream>
#include <ctime>

using namespace std;
using namespace apache::thrift;
using namespace apache::thrift::protocol;
using namespace apache::thrift::transport;

class fullthriftclient : public QObject
{
    Q_OBJECT
public:
    explicit fullthriftclient(string name, QObject *parent = 0);

signals:

public slots:
};

#endif // FULLTHRIFTCLIENT_H
