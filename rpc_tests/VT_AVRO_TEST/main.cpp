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
    std::string msg;

    std::ifstream fl("/home/groenendael/test_data/200file.bin");
    fl.seekg( 0, std::ios::end );
    size_t len = fl.tellg();
    char *buf = new char[len];
    fl.seekg(0, std::ios::beg);
    fl.read(buf, len);
    fl.close();
    std::string s(buf, len);

    //test::file_content dst_obj;
    //test::file_content src_obj;
    //src_obj.set_line(s);

    for (int i = 0; i<1000; ++i)
    {
        s1 = clock();
        //src_obj.SerializeToString(&msg);
        f1 = clock();
        ser_time += f1 - s1;
	std::cout << s1 << "ser" << f1 << std::endl;

        ser_val += msg.capacity();

        s2 = clock();
        //dst_obj.ParseFromString(msg);
        f2 = clock();
        deser_time += f2 - s2;
	std::cout << s2 << "deser" << f2 << std::endl;
    }

    //std::ofstream fout("VT_AVRO_SER_results.txt", std::ios::app);
    std::cout << "for " << "/home/groenendael/test_data/200file.bin" << " file: "
         << "ser_middltime " << (ser_time/10)/CLOCKS_PER_SEC << " sec"
         << "; desr_middletime " << (deser_time/10)/CLOCKS_PER_SEC << " sec"
         << "; src_file of " << len << " byte"
         << "; midle_trans_pack of " << ser_val/10 << " bytes" << std::endl;

    //fout.close();

    return a.exec();
    //a.quit();
}

