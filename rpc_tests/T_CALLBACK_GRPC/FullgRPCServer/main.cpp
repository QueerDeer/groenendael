#include <QCoreApplication>
#include "grpcserver.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    GrpcServer server;

    return a.exec();
}

