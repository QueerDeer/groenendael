#include <QCoreApplication>
#include <zmq.h>
#include <zmq_utils.h>
#include "test.pb.h"
#include <string>
#include <iostream>
#include <fstream>
#include <ctime>
#include <QFile>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    void *context = zmq_ctx_new ();
    void *requester = zmq_socket (context, ZMQ_REQ);
    zmq_connect (requester, "tcp://localhost:5555");
    printf ("Connected\n");

    clock_t s1, s2;
    double time = 0.0;
    int real_size;
    std::string msg;

    std::ifstream fl(argv[1]);
//    std::ifstream fl("/home/groenendael/test_data/200file.txt");
    fl.seekg( 0, std::ios::end );
    size_t len = fl.tellg();
    char *buf = new char[len];
    fl.seekg(0, std::ios::beg);
    fl.read(buf, len);
    fl.close();
    std::string s(buf, len);

    test::file_content resp_obj;
    test::file_content src_obj;
    src_obj.set_line(s);
    s.clear();

    for(int i = 0; i<1; ++i)
    {
        s1 = clock();
        src_obj.SerializeToString(&msg);
        real_size = msg.capacity();
        std::cout << real_size << std::endl;

        char *buffer = new char[real_size];
        std::string resp(buffer, real_size);

        int send_index = 0;
        int send_size = real_size;
        int recieve_index = 0;
        int recieve_size = real_size;

        while (send_size>0)
        {
            int sended_size = zmq_send (requester, &msg[send_index], 100000, ZMQ_SNDMORE);
            send_index+=sended_size;
            send_size-=sended_size;
        }
        zmq_send (requester, "", strlen(""), 0);

        while (recieve_size >0 )
        {
            int read_size = zmq_recv (requester, &resp[recieve_index], 100000, ZMQ_SNDMORE);
            recieve_index+=read_size;
            recieve_size-=read_size;
        }

        resp_obj.ParseFromString(resp);
        s2 = clock();
        time += s2 - s1;
        std::cout << resp_obj.ByteSize() << std::endl;
    }

    std::cout << time/CLOCKS_PER_SEC << std::endl;

    std::ofstream fout("T_CALLBACK_ZMQ_PROTO_results.txt", std::ios::app);
    fout << "for " << argv[1] << " file, zmq socket and protobuf: "
         << "callback_ltime " << (time/1)/CLOCKS_PER_SEC << " sec"
         << std::endl;

    fout.close();

    zmq_close (requester);
    zmq_ctx_destroy (context);

//    return a.exec();
    a.quit();
}

