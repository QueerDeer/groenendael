#include "fullthriftclient.h"

fullthriftclient::fullthriftclient(QObject *parent) : QObject(parent)
{

    try {

    boost::shared_ptr<TTransport> socket(new TSocket("localhost", 9090));
    boost::shared_ptr<TTransport> transport(new TBufferedTransport(socket));
    boost::shared_ptr<TProtocol> protocol(new TBinaryProtocol(transport));
    MessageManagerClient client(protocol);

    transport->open();

    client.ping();

    message *msg = new message();
    msg->uid = 21;
    msg->line = "Hi, server, it,s thrift-line, looooooooooooooooong-loooooooong-looooong-long.";

    client.add_message(*msg);

    transport->close();

    } catch(InvalidValueException e) {
        std::cout << "something wrong" << e.error_msg << std::endl;
    }
}

