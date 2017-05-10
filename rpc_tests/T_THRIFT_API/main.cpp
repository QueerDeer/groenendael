#include <QCoreApplication>
#include<stdio.h>
#include<string.h>    //strlen
#include<sys/socket.h>
#include<arpa/inet.h> //inet_addr
#include<unistd.h>    //write
#include<fstream>
#include <ctime>
#include<iostream>
    #include <fcntl.h>
#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/protocol/TCompactProtocol.h>
#include <thrift/protocol/TJSONProtocol.h>
#include <thrift/transport/TBufferTransports.h>
#include "gen-cpp/test_types.h"

using namespace boost;
using namespace std;
using namespace apache::thrift;
using apache::thrift::protocol::TBinaryProtocol;
using apache::thrift::protocol::TCompactProtocol;
using apache::thrift::protocol::TJSONProtocol;
using apache::thrift::transport::TMemoryBuffer;
using apache::thrift::transport::TTransportException;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    clock_t s1, s2;
    double time = 0.0;
    std::string msg;

    std::ifstream fl(argv[1]);
    fl.seekg( 0, std::ios::end );
    size_t len = fl.tellg();
    char *buf = new char[len];
    fl.seekg(0, std::ios::beg);
    fl.read(buf, len);
    fl.close();
    std::string s(buf, len);

    shared_ptr<TMemoryBuffer> buffer(new TMemoryBuffer());
    shared_ptr<TJSONProtocol> proto(new TJSONProtocol(buffer));

    static std::auto_ptr<file_content> message;
    message.reset(new file_content);
    message->line = s;

    message->write(proto.get());
    msg = buffer->getBufferAsString();
    //msg = s;
    int real_size = msg.capacity();
    std::cout << real_size << std::endl;



    int socket_desc , client_sock , c;
    struct sockaddr_in server , client;

    socket_desc = socket(AF_INET , SOCK_STREAM , 0);
    if (socket_desc == -1)
    {
        printf("Could not create socket");
    }
    puts("Socket created");

    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons( 8888 );

    if( bind(socket_desc,(struct sockaddr *)&server , sizeof(server)) < 0)
    {
        perror("bind failed. Error");
        return 1;
    }
    puts("bind done");

    listen(socket_desc , 3);

    puts("Waiting for incoming connections...");
    c = sizeof(struct sockaddr_in);



    int sock;
    struct sockaddr_in server_;

    //Create socket
    sock = socket(AF_INET , SOCK_STREAM , 0);
    if (sock == -1)
    {
        printf("Could not create socket");
    }
    puts("Socket created");

    server_.sin_addr.s_addr = inet_addr("127.0.0.1");
    server_.sin_family = AF_INET;
    server_.sin_port = htons( 8888 );

    if (connect(sock , (struct sockaddr *)&server_, sizeof(server_)) < 0)
    {
        perror("connect failed. Error");
        return 1;
    }




    client_sock = accept(socket_desc, (struct sockaddr *)&client, (socklen_t*)&c);
    if (client_sock < 0)
    {
        perror("accept failed");
        return 1;
    }
//    fcntl(client_sock, F_SETFL, O_NONBLOCK);
//    fcntl(sock, F_SETFL, O_NONBLOCK);
    puts("Connection accepted");


for (int j = 0; j<1; ++j)
{
    int send_index = 0;
    int send_size = real_size;
    int recieve_index = 0;
    int recieve_size = real_size;

    char *buffer = new char[real_size];
    std::string client_message(buffer, real_size);
    std::cout << strlen(&client_message[0]) << std::endl;

    s1 = clock();
    while (recieve_size >0 || send_size>0)
    {
        int sended_size = send(sock , &msg[send_index] , 1000000 , 0);
        send_index+=sended_size;
        send_size-=sended_size;

        int read_size = recv(client_sock , &client_message[recieve_index] , 1000000 , 0);
        recieve_index+=read_size;
        recieve_size-=read_size;
    }
    s2 = clock();

    time = s2 - s1;
    puts("got it:");
    std::cout << client_message.capacity() << std::endl;
    std::cout << strlen(&client_message[0]) << std::endl;
    puts("in time of");
    std::cout << time/CLOCKS_PER_SEC << std::endl;
    std::cout << (client_message == msg) << std::endl;
}

std::ofstream fout("T_THRIFT_API_results.txt", std::ios::app);
fout << "for " << argv[1] << " file and thrift_JSON: "
     << "api_middltime " << (time)/CLOCKS_PER_SEC << " sec"
     << std::endl;

fout.close();

    close(sock);
    close(socket_desc);
    a.quit();
}

