#ifndef FULLTHRIFTSERVER_H
#define FULLTHRIFTSERVER_H

#include <QObject>
#include <iostream>
#include "gen-cpp/MessageManager.h"
#include <thrift/protocol/TDebugProtocol.h>
#include <thrift/protocol/TBinaryProtocol.h>
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

  void ping() {
    printf("pong\n");
  }

  int32_t add_message(const message& m) {

      if (!m.line.length())
          throw InvalidValueException();
      if (m.uid <= 0)
          throw InvalidValueException();

      const std::string result(apache::thrift::ThriftDebugString(m));
      std::cout << result << " on-server deserialized view" << std::endl;

    printf("add_message\n");
  }

  void get_message(message& _return, const int32_t uid) {
    printf("get_message\n");
  }

  void clear_list() {

    printf("clear_list\n");
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
