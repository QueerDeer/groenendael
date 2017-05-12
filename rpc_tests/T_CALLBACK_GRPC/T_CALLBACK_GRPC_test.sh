#!/bin/bash

./FullgRPCServer/FullgRPCServer &
./FullgRPCClient/FullgRPCClient /home/groenendael/test_data/200file.txt
./FullgRPCClient/FullgRPCClient /home/groenendael/test_data/200file.bin
./FullgRPCClient/FullgRPCClient /home/groenendael/test_data/400file.txt
./FullgRPCClient/FullgRPCClient /home/groenendael/test_data/400file.bin
./FullgRPCClient/FullgRPCClient /home/groenendael/test_data/600file.txt
./FullgRPCClient/FullgRPCClient /home/groenendael/test_data/600file.bin
./FullgRPCClient/FullgRPCClient /home/groenendael/test_data/800file.txt
./FullgRPCClient/FullgRPCClient /home/groenendael/test_data/800file.bin
./FullgRPCClient/FullgRPCClient /home/groenendael/test_data/1000file.txt
./FullgRPCClient/FullgRPCClient /home/groenendael/test_data/1000file.bin
killall ./FullgRPCServer/FullgRPCServer
