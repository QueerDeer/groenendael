#!/bin/bash

./ZMQProtoServer/ZMQProtoServer &
./ZMQProtoClient/ZMQProtoClient /home/groenendael/test_data/200file.txt
./ZMQProtoClient/ZMQProtoClient /home/groenendael/test_data/200file.bin
./ZMQProtoClient/ZMQProtoClient /home/groenendael/test_data/400file.txt
./ZMQProtoClient/ZMQProtoClient /home/groenendael/test_data/400file.bin
./ZMQProtoClient/ZMQProtoClient /home/groenendael/test_data/600file.txt
./ZMQProtoClient/ZMQProtoClient /home/groenendael/test_data/600file.bin
./ZMQProtoClient/ZMQProtoClient /home/groenendael/test_data/800file.txt
./ZMQProtoClient/ZMQProtoClient /home/groenendael/test_data/800file.bin
./ZMQProtoClient/ZMQProtoClient /home/groenendael/test_data/1000file.txt
./ZMQProtoClient/ZMQProtoClient /home/groenendael/test_data/1000file.bin
killall ./ZMQProtoServer/ZMQProtoServer
