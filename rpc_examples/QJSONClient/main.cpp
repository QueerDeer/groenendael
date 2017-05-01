#include <QCoreApplication>
#include "tcpjsonclient.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    tcpjsonclient client;

    return a.exec();
}

