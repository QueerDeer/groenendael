#include <QCoreApplication>
#include "tcpjsonserver.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    tcpjsonserver server;

    return a.exec();
}

