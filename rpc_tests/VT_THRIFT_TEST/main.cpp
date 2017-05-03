#include <QCoreApplication>
#include <iostream>
#include <fstream>
#include <ctime>
#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/protocol/TCompactProtocol.h>
#include <thrift/protocol/TJSONProtocol.h>
#include <thrift/transport/TBufferTransports.h>
#include "gen-cpp/test_types.h"

using namespace boost;
using namespace std;
using namespace apache::thrift;
using apache::thrift::protocol::TBinaryProtocol;
using apache::thrift::protocol::TCompactProtocol;
using apache::thrift::protocol::TJSONProtocol;
using apache::thrift::transport::TMemoryBuffer;
using apache::thrift::transport::TTransportException;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    clock_t s1, s2, f1, f2;
    double ser_time = 0.0;
    double ser_val = 0.0;
    double deser_time = 0.0;

    std::ifstream fl(argv[1]);
    fl.seekg( 0, std::ios::end );
    size_t len = fl.tellg();
    char *buf = new char[len];
    fl.seekg(0, std::ios::beg);
    fl.read(buf, len);
    fl.close();
    std::string s(buf, len);

    for (int i = 0; i<1000; ++i)
    {
        shared_ptr<TMemoryBuffer> buffer(new TMemoryBuffer());
        shared_ptr<TBinaryProtocol> proto(new TBinaryProtocol(buffer));
        shared_ptr<TMemoryBuffer> buffer2(new TMemoryBuffer());
        shared_ptr<TBinaryProtocol> proto2(new TBinaryProtocol(buffer2));
        std::string serialized_string;

        static std::auto_ptr<file_content> msg;
        static std::auto_ptr<file_content> msg2;
        msg.reset(new file_content);
        msg->line = s;

        s1 = clock();
        msg->write(proto.get());
        f1 = clock();
        ser_time += f1 - s1;

        serialized_string = buffer->getBufferAsString();
        ser_val += serialized_string.capacity();

        buffer2->resetBuffer((uint8_t*)serialized_string.data(), static_cast<uint32_t>(serialized_string.length()));
        msg2.reset(new file_content);

        s2 = clock();
        msg2->read(proto2.get());
        f2 = clock();
        deser_time += f2 - s2;

        buffer.reset();
        proto.reset();
        buffer2.reset();
        proto2.reset();
        msg.reset();
        msg2.reset();
        serialized_string.clear();

    }

    std::ofstream fout("VT_THRIFT_SER_results.txt", std::ios::app);

    fout << "for " << argv[1] << " file and binary protocol: "
         << "ser_middltime " << (ser_time/1000)/CLOCKS_PER_SEC << " sec"
         << "; desr_middletime " << (deser_time/1000)/CLOCKS_PER_SEC << " sec"
         << "; src_file of " << len << " byte"
         << "; midle_trans_pack of " << ser_val/1000 << " bytes"
         << std::endl;

    fout.close();

    ser_time = 0.0;
    ser_val = 0.0;
    deser_time = 0.0;

    for (int i = 0; i<1000; ++i)
    {
        shared_ptr<TMemoryBuffer> buffer(new TMemoryBuffer());
        shared_ptr<TCompactProtocol> proto(new TCompactProtocol(buffer));
        shared_ptr<TMemoryBuffer> buffer2(new TMemoryBuffer());
        shared_ptr<TCompactProtocol> proto2(new TCompactProtocol(buffer2));
        std::string serialized_string;

        static std::auto_ptr<file_content> msg;
        static std::auto_ptr<file_content> msg2;
        msg.reset(new file_content);
        msg->line = s;

        s1 = clock();
        msg->write(proto.get());
        f1 = clock();
        ser_time += f1 - s1;

        serialized_string = buffer->getBufferAsString();
        ser_val += serialized_string.capacity();

        buffer2->resetBuffer((uint8_t*)serialized_string.data(), static_cast<uint32_t>(serialized_string.length()));
        msg2.reset(new file_content);

        s2 = clock();
        msg2->read(proto2.get());
        f2 = clock();
        deser_time += f2 - s2;

        buffer.reset();
        proto.reset();
        buffer2.reset();
        proto2.reset();
        msg.reset();
        msg2.reset();
        serialized_string.clear();
    }

    fout.open("VT_THRIFT_SER_results.txt", std::ios::app);

    fout << "for " << argv[1] << " file and compact protocol: "
         << "ser_middltime " << (ser_time/1000)/CLOCKS_PER_SEC << " sec"
         << "; desr_middletime " << (deser_time/1000)/CLOCKS_PER_SEC << " sec"
         << "; src_file of " << len << " byte"
         << "; midle_trans_pack of " << ser_val/1000 << " bytes"
         << std::endl;

    fout.close();

    ser_time = 0.0;
    ser_val = 0.0;
    deser_time = 0.0;

    for (int i = 0; i<1000; ++i)
    {
        shared_ptr<TMemoryBuffer> buffer(new TMemoryBuffer());
        shared_ptr<TJSONProtocol> proto(new TJSONProtocol(buffer));
        shared_ptr<TMemoryBuffer> buffer2(new TMemoryBuffer());
        shared_ptr<TJSONProtocol> proto2(new TJSONProtocol(buffer2));
        std::string serialized_string;
        static std::auto_ptr<file_content> msg;
        static std::auto_ptr<file_content> msg2;

        msg.reset(new file_content);
        msg->line = s;

        s1 = clock();
        msg->write(proto.get());
        f1 = clock();
        ser_time += f1 - s1;

        serialized_string = buffer->getBufferAsString();
        ser_val += serialized_string.capacity();

        buffer2->resetBuffer((uint8_t*)serialized_string.data(), static_cast<uint32_t>(serialized_string.length()));
        msg2.reset(new file_content);

        s2 = clock();
        msg2->read(proto2.get());
        f2 = clock();
        deser_time += f2 - s2;

        buffer.reset();
        proto.reset();
        buffer2.reset();
        proto2.reset();
        msg.reset();
        msg2.reset();
        serialized_string.clear();
    }

    fout.open("VT_THRIFT_SER_results.txt", std::ios::app);

    fout << "for " << argv[1] << " file and JSON protocol: "
         << "ser_middltime " << (ser_time/1000)/CLOCKS_PER_SEC << " sec"
         << "; desr_middletime " << (deser_time/1000)/CLOCKS_PER_SEC << " sec"
         << "; src_file of " << len << " byte"
         << "; midle_trans_pack of " << ser_val/1000 << " bytes"
         << std::endl;

    fout.close();

    //return a.exec();
    a.quit();
}

