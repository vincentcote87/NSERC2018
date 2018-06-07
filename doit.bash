#!/bin/bash
rm -f compilationmessage
g++ -std=c++11 -I /usr/local/include -L /usr/local/lib64 integrator.cc -o integrator -lprimesieve -lmpfr -lgmp -Wl,-rpath=/usr/local/lib64  -static &> compilationmessage
less compilationmessage
