#include <QCoreApplication>
#include "tcpavroserver.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    tcpavroserver server;

    return a.exec();
}

