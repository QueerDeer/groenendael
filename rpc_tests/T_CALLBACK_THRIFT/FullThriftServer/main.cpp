#include <QCoreApplication>
#include "fullthriftserver.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    fullthriftserver server;

    return a.exec();
}

