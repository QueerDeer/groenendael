#include <QCoreApplication>
#include <zmq.h>
#include <zmq_utils.h>
#include <QJsonDocument>
#include <QJsonObject>
#include <iostream>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    void *context = zmq_ctx_new ();
    void *responder = zmq_socket (context, ZMQ_REP);
    zmq_bind (responder, "tcp://*:5555");
    printf ("Binded\n");

    for(int i = 0; i<3; i++)
    {
        char buffer [256];
        memset( buffer, '\0', 256 * sizeof(char));
        zmq_recv (responder, buffer, 256, 0);
        printf ("Received\n");
        std::string s(buffer, sizeof(buffer));
        //std::string s = "{\n    \"test\": {\n        \"message\": \"Let it be, let it be, type this line and flee\",\n        \"uid\": 42\n    }\n}\n";
        QByteArray byteArray(s.c_str(), s.length());
        QJsonDocument doc (QJsonDocument::fromJson(byteArray.data()));
        std::cout << doc.toJson().data() << " decoded string" << std::endl;
    }

    return a.exec();
}

