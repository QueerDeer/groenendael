#include "fullthriftserver.h"

fullthriftserver::fullthriftserver(QObject *parent) : QObject(parent)
{

    shared_ptr<MessageManagerHandler> handler(new MessageManagerHandler());
    shared_ptr<TProcessor> processor(new MessageManagerProcessor(handler));
    shared_ptr<TServerTransport> serverTransport(new TServerSocket(9090));
    shared_ptr<TTransportFactory> transportFactory(new TBufferedTransportFactory());
//    shared_ptr<TProtocolFactory> protocolFactory(new TBinaryProtocolFactory());
//    shared_ptr<TProtocolFactory> protocolFactory(new TCompactProtocolFactory());
    shared_ptr<TProtocolFactory> protocolFactory(new TJSONProtocolFactory());

    TSimpleServer server(processor, serverTransport, transportFactory, protocolFactory);
    server.serve();

}

