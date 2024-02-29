#!/bin/sh

path=`realpath $0`
dir=`dirname $path`

# $dir now refers to the directory in which this script actually lives
# g++ $dir/main.cpp -o $dir/main

rm -f matmul  errors.o main.o OneDArray.o
g++ -g -Wall    -c -o errors.o errors.cc
g++ -g -Wall    -c -o main.o main.cpp
g++ -g -Wall    -c -o OneDArray.o OneDArray.cc
g++  errors.o main.o OneDArray.o -o vecsum

