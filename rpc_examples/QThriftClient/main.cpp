#include <QCoreApplication>
#include "tcpthriftclient.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    tcpthriftclient client;

    return a.exec();
}

