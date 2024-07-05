#!/bin/bash

gcc -c -fPIC strutils.c -o strutils.o
gcc -shared -o libstrutils.so strutils.o
sudo mv libstrutils.so /usr/local/lib/
sudo cp strutils.h /usr/local/include/
sudo ldconfig
