#include <QCoreApplication>
#include <zmq.h>
#include <zmq_utils.h>
#include <QJsonDocument>
#include <QJsonObject>
#include <string>
#include <iostream>
#include <QFile>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    void *context = zmq_ctx_new ();
    void *requester = zmq_socket (context, ZMQ_REQ);
    zmq_connect (requester, "tcp://localhost:5555");
    printf ("Connected\n");

    QFile file;
    file.setFileName("test.json");
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QString str = file.readAll();
    file.close();

    QJsonDocument doc = QJsonDocument::fromJson(str.toUtf8());
    QByteArray array = doc.toJson();
    std::cout << array.data() << std::endl;


        zmq_send (requester, array, array.length(), ZMQ_SNDMORE);
        zmq_send (requester, array, array.length(), ZMQ_SNDMORE);
        zmq_send (requester, array, array.length(), 0);
        printf ("Sended\n");

    zmq_close (requester);
    zmq_ctx_destroy (context);

    return a.exec();
}

