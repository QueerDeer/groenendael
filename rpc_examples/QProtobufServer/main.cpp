#include <QCoreApplication>
#include "tcpprotoserver.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    tcpprotoserver server;

    return a.exec();
}

