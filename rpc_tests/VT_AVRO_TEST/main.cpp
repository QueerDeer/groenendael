#include <QCoreApplication>
#include <iostream>
#include <fstream>
#include <ctime>
#include "avro/ValidSchema.hh"
#include "avro/Compiler.hh"
#include "avro/Reader.hh"
#include "test.hh"

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
    std::vector<uint8_t> v(s.begin(), s.end());

    avro::EncoderPtr eB = avro::binaryEncoder();

    for (int i = 0; i<1000; ++i)
    {
        std::auto_ptr<avro::OutputStream> out = avro::memoryOutputStream();
        eB->init(*out);
        c::file_content message_out;
        message_out.line = v;
        s1 = clock();
        avro::encode(*eB, message_out);
        f1 = clock();
        ser_time += f1 - s1;
        eB->flush();

        ser_val += out->byteCount();
        std::auto_ptr<avro::InputStream> in = avro::memoryInputStream(*out);
        avro::DecoderPtr dB = avro::binaryDecoder();
        dB->init(*in);
        c::file_content message_in;
        s2 = clock();
        avro::decode(*dB, message_in);
        f2 = clock();
        deser_time += f2 - s2;

        out.reset();
        in.reset();

    }

    std::ofstream fout("VT_AVRO_SER_results.txt", std::ios::app);
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

    std::ifstream input("test.json");
    avro::ValidSchema testSchema;
    avro::compileJsonSchema(input, testSchema);

    avro::EncoderPtr e = avro::jsonEncoder(testSchema);

    for (int i = 0; i<1000; ++i)
    {
        std::auto_ptr<avro::OutputStream> out = avro::memoryOutputStream();
        e->init(*out);
        c::file_content message_out;
        message_out.line = v;
        s1 = clock();
        avro::encode(*e, message_out);
        f1 = clock();
        ser_time += f1 - s1;
        e->flush();

        ser_val += out->byteCount();
        std::auto_ptr<avro::InputStream> in = avro::memoryInputStream(*out);
        avro::DecoderPtr d = avro::jsonDecoder(testSchema);
        d->init(*in);
        c::file_content message_in;
        s2 = clock();
        avro::decode(*d, message_in);
        f2 = clock();
        deser_time += f2 - s2;

        out.reset();
        in.reset();

    }

    fout.open("VT_AVRO_SER_results.txt", std::ios::app);
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

