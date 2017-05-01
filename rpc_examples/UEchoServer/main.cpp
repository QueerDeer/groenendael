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

    int server_fd, client_fd;
    struct sockaddr_in server, client;
    char buf[2048];
    int opt_val = 1;

    server_fd = socket(AF_INET, SOCK_STREAM, 0);

    server.sin_family = AF_INET;
    server.sin_port = htons(6000);
    server.sin_addr.s_addr = htonl(INADDR_ANY);


    setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt_val, sizeof opt_val);
    bind(server_fd, (struct sockaddr *) &server, sizeof(server));
    listen(server_fd, 128);

    while (1)
    {
        socklen_t client_len = sizeof(client);
        client_fd = accept(server_fd, (struct sockaddr *) &client, &client_len);


        while ((recv(client_fd, buf, 2048, 0))>0)
        {
            write(client_fd, buf, strlen(buf));
            std::cout << buf << std::endl;
            memset(&buf[0], 0, sizeof(buf));
        }

    }


    return a.exec();
}
