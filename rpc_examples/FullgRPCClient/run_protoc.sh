#!/bin/bash


grpc_plugin=`which grpc_cpp_plugin`

protoc --cpp_out=. test.proto
protoc --grpc_out=. --plugin=protoc-gen-grpc=$grpc_plugin test.proto

