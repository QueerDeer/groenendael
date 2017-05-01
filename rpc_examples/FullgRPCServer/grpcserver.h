#ifndef GRPCSERVER_H
#define GRPCSERVER_H


#include <iostream>
#include <memory>
#include <string>

#include <grpc++/grpc++.h>

#include "test.grpc.pb.h"

using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::Status;
using test::Hello;
using test::test_line;
using test::Greeter;

class TestServiceImpl final : public Greeter::Service {
  Status SendLine(ServerContext* context, const Hello* request,
                  test_line* reply) override {
    reply->set_uid(21);
    reply->set_line(request->name());
    return Status::OK;
  }
};


class GrpcServer
{
public:
    GrpcServer();

    void RunServer() {
      std::string server_address("0.0.0.0:9000");
      TestServiceImpl service;

      ServerBuilder builder;
      builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());
      builder.RegisterService(&service);
      std::unique_ptr<Server> server(builder.BuildAndStart());
      std::cout << "running on " << server_address << std::endl;
      server->Wait();
    }
};

#endif // GRPCSERVER_H
