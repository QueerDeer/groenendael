#include <QCoreApplication>
#include "grpcclient.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    GrpcClient client(grpc::CreateChannel(
          "localhost:9000", grpc::InsecureChannelCredentials()));
    std::string request("put it in line");
    std::string reply = client.SendLine(request);
    std::cout << "line received: " << reply << std::endl;

    return a.exec();
}

