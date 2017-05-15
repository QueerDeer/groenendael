#include <QCoreApplication>
#include <zmq.h>
#include <zmq_utils.h>
#include "test.pb.h"
#include <iostream>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    void *context = zmq_ctx_new ();
    void *responder = zmq_socket (context, ZMQ_REP);
    zmq_bind (responder, "tcp://*:5555");
    printf ("Binded\n");

    test::file_content recv_obj;
    std::string msg;

    for(;;)
    {
        char *buffer = new char[1610612736];
        std::string s(buffer, 1610612736);
        int check = 0;
        int back = 0;

        while(true)
        {
            check = zmq_recv (responder, &s[check], 100000, 0);
            if (check < 0) break;
        }
        recv_obj.ParseFromString(s);
        recv_obj.SerializeToString(&msg);
        while(true)
        {
            check = zmq_send (responder, &msg[back], 100000, 0);
            back += check;
            if (check < 0) break;
        }
        std::cout << msg.capacity() << std::endl;
    }

    return a.exec();
}

