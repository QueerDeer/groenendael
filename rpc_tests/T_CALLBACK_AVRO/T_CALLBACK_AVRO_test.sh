#!/bin/bash

python ./FullAvroServer/FullAvroServer.py &
python ./FullAvroClient/FullAvroClient.py 100 /home/groenendael/test_data/200file.txt
python ./FullAvroClient/FullAvroClient.py 100 /home/groenendael/test_data/200file.bin
python ./FullAvroClient/FullAvroClient.py 100 /home/groenendael/test_data/400file.txt
python ./FullAvroClient/FullAvroClient.py 100 /home/groenendael/test_data/400file.bin
python ./FullAvroClient/FullAvroClient.py 100 /home/groenendael/test_data/600file.txt
python ./FullAvroClient/FullAvroClient.py 100 /home/groenendael/test_data/600file.bin
python ./FullAvroClient/FullAvroClient.py 100 /home/groenendael/test_data/800file.txt
python ./FullAvroClient/FullAvroClient.py 100 /home/groenendael/test_data/800file.bin
python ./FullAvroClient/FullAvroClient.py 100 /home/groenendael/test_data/1000file.txt
python ./FullAvroClient/FullAvroClient.py 100 /home/groenendael/test_data/1000file.bin
killall ./FullAvroServer/FullAvroServer
