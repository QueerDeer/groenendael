#include <QCoreApplication>

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <iostream>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    int clientSocket;
    struct sockaddr_in serverAddr;
    char buffer[2048];
    socklen_t addr_size;

    clientSocket = socket(AF_INET, SOCK_STREAM, 0);

    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(6000);
    serverAddr.sin_addr.s_addr = htonl(INADDR_ANY);

    addr_size = sizeof serverAddr;
    connect(clientSocket, (struct sockaddr *) &serverAddr, addr_size);

    while (1)
    {
        scanf("%s" , buffer);
        send(clientSocket, buffer, strlen(buffer), 0);
        recv(clientSocket, buffer, 2048, 0);
        std::cout << buffer << std::endl;
    }


    return a.exec();
}

