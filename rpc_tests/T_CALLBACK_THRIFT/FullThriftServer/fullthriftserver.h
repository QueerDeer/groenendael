#ifndef FULLTHRIFTSERVER_H
#define FULLTHRIFTSERVER_H

#include <QObject>
#include <iostream>
#include "gen-cpp/MessageManager.h"
#include <thrift/protocol/TDebugProtocol.h>
#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/protocol/TCompactProtocol.h>
#include <thrift/protocol/TJSONProtocol.h>
#include <thrift/server/TSimpleServer.h>
#include <thrift/transport/TServerSocket.h>
#include <thrift/transport/TBufferTransports.h>

using namespace ::apache::thrift;
using namespace ::apache::thrift::protocol;
using namespace ::apache::thrift::transport;
using namespace ::apache::thrift::server;

using boost::shared_ptr;

class MessageManagerHandler : virtual public MessageManagerIf {
 public:
  MessageManagerHandler() {
  }

  void add_message(message& _return, const message& m) {

      if (!m.line.length())
          throw InvalidValueException();

      _return = m;
//      printf("add_message\n");
  }

};

class fullthriftserver : public QObject
{
    Q_OBJECT
public:
    explicit fullthriftserver(QObject *parent = 0);

signals:

public slots:
};

#endif // FULLTHRIFTSERVER_H
