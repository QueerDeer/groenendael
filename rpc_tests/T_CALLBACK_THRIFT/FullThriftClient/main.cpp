#include <QCoreApplication>
#include "fullthriftclient.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
//    std::string name = argv[1];
    std::string name = "lol";
    fullthriftclient client(name);

//    return a.exec();
    a.quit();
}

