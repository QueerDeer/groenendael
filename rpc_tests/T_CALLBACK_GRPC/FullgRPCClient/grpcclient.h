#ifndef GRPCCLIENT_H
#define GRPCCLIENT_H


#include <iostream>
#include <memory>
#include <string>

#include <grpc++/grpc++.h>

#include "test.grpc.pb.h"

using grpc::Channel;
using grpc::ChannelArguments;
using grpc::ClientContext;
using grpc::Status;
using test::Hello;
using test::test_line;
using test::Greeter;

class GrpcClient {
public:
    GrpcClient(std::shared_ptr<Channel> channel)
        : stub_(Greeter::NewStub(channel)) {}

    std::string SendLine(const std::string& line) {
        Hello request;
        request.set_name(line);
        test_line reply;
        ClientContext context;

        Status status = stub_->SendLine(&context, request, &reply);
        if (status.ok()) {
            return reply.line();
        } else {
            //return 0;
            std::cout << status.error_code() << ": " << status.error_message()
                      << std::endl;
        }
    }

private:
    std::unique_ptr<Greeter::Stub> stub_;
};

#endif // GRPCCLIENT_H
