#include <QCoreApplication>
#include "tcpavroclient.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    tcpavroclient client;

    return a.exec();
}

