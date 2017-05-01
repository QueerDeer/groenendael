#include <QCoreApplication>
#include "fullthriftclient.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    fullthriftclient client;

    return a.exec();
}

