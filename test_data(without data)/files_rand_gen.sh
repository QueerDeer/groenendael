#!/bin/bash

tr -dc A-Za-z0-9[:space:] </dev/urandom | head -c 200m > 200file.txt
tr -dc A-Za-z0-9[:space:] </dev/urandom | head -c 400m > 400file.txt
tr -dc A-Za-z0-9[:space:] </dev/urandom | head -c 600m > 600file.txt
tr -dc A-Za-z0-9[:space:] </dev/urandom | head -c 800m > 800file.txt
tr -dc A-Za-z0-9[:space:] </dev/urandom | head -c 1000m > 1000file.txt
head -c 200m /dev/urandom > 200file.bin
head -c 400m /dev/urandom > 400file.bin
head -c 600m /dev/urandom > 600file.bin
head -c 800m /dev/urandom > 800file.bin
head -c 1000m /dev/urandom > 1000file.bin
