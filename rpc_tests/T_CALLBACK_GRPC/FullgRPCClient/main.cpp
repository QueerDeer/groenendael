#include <QCoreApplication>
#include <fstream>
#include <ctime>
#include <cstring>
#include "grpcclient.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    clock_t s1, s2;
    double time = 0.0;

    std::ifstream fl(argv[1]);
//    std::ifstream fl("/home/groenendael/test_data/200file.txt"); //for debugging
    fl.seekg( 0, std::ios::end );
    size_t len = fl.tellg();
    char *buf = new char[len];
    fl.seekg(0, std::ios::beg);
    fl.read(buf, len);
    fl.close();
    std::string message(buf, len);
    std::cout << len << std::endl;

    GrpcClient client(grpc::CreateChannel(
                          "localhost:9000", grpc::InsecureChannelCredentials()));

//    char request[4194299]; //way one

    for (int j = 0; j<1000; ++j)
    {
        std::string reply;
        s1 = clock();
        for (int i = 0; i<len; i+=4194299)
        {
//            memcpy(&request[0u], &message[i], 4194299); //way one
            std::string request (message.begin()+i, message.begin()+i+4194299); //way two
            reply += client.SendLine(request);
            request.clear(); //way two
        }
        s2 = clock();
        time += s2 - s1;
//        std::cout << "line received: " << (reply==message) << std::endl; //for debugging
        reply.clear();
    }

    std::cout << "line received in " << (time/1000)/CLOCKS_PER_SEC << std::endl;
    std::ofstream fout("T_CALLBACK_GRPC_results.txt", std::ios::app);
    fout << "for " << argv[1] << " file and grpc: "
         << "callback_time = " << (time/1000)/CLOCKS_PER_SEC << " sec"
         << std::endl;

    fout.close();
    //return a.exec();
    a.quit();
}

