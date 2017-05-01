#include <QCoreApplication>
#include "tcpprotoclient.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    tcpprotoclient client;

    return a.exec();
}

