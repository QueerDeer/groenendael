#include "fullthriftclient.h"

fullthriftclient::fullthriftclient(string name, QObject *parent) : QObject(parent)
{

    try {

        boost::shared_ptr<TTransport> socket(new TSocket("localhost", 9090));
        boost::shared_ptr<TTransport> transport(new TBufferedTransport(socket));
        boost::shared_ptr<TProtocol> protocol(new TBinaryProtocol(transport));
//        boost::shared_ptr<TProtocol> protocol(new TCompactProtocol(transport));
//        boost::shared_ptr<TProtocol> protocol(new TJSONProtocol(transport));
        MessageManagerClient client(protocol);

        transport->open();

        message *back = new message();
        message *msg = new message();

//        std::ifstream fl(&name[0]);
        std::ifstream fl("/home/groenendael/test_data/1000file.txt");
        fl.seekg( 0, std::ios::end );
        size_t len = fl.tellg();
        char *buf = new char[len];
        fl.seekg(0, std::ios::beg);
        fl.read(buf, len);
        fl.close();
        std::string s(buf, len);

        msg->line = s;

        clock_t s1, s2;
        double time = 0;

        for (int i = 0; i<21; ++i)
        {
            s1=clock();
            client.add_message(*back, *msg);
            s2=clock();
            time += s2 - s1;
            std::cout << back->line.capacity() << std::endl;
        }

//        std::ofstream fout("T_CALLBACK__THRIFT_results.txt", std::ios::app);
//        fout << "for " << name << " file and thrift_binary: "
//             << "callback_time " << (time/21)/CLOCKS_PER_SEC << " sec"
//             << std::endl;

//        fout.close();

        transport->close();

    } catch(InvalidValueException e) {
        std::cout << "something wrong" << e.error_msg << std::endl;
    }
}

