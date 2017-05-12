#!/bin/bash

./FullThriftServer/FullThriftServer &
./FullThriftClient/FullThriftClient /home/groenendael/test_data/200file.txt
./FullThriftClient/FullThriftClient /home/groenendael/test_data/200file.bin
./FullThriftClient/FullThriftClient /home/groenendael/test_data/400file.txt
./FullThriftClient/FullThriftClient /home/groenendael/test_data/400file.bin
./FullThriftClient/FullThriftClient /home/groenendael/test_data/600file.txt
./FullThriftClient/FullThriftClient /home/groenendael/test_data/600file.bin
./FullThriftClient/FullThriftClient /home/groenendael/test_data/800file.txt
./FullThriftClient/FullThriftClient /home/groenendael/test_data/800file.bin
./FullThriftClient/FullThriftClient /home/groenendael/test_data/1000file.txt
./FullThriftClient/FullThriftClient /home/groenendael/test_data/1000file.bin
killall ./FullThriftServer/FullThriftServer
