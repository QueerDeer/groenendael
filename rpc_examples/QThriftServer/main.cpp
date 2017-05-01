#include <QCoreApplication>
#include "tcpthriftserver.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    tcpthriftserver server;

    return a.exec();
}

