#!/bin/sh

if [ ! -d "build" ]; then
    mkdir build
fi

if [ ! -d "build/bin" ]; then
    mkdir build/bin
fi

cd build

cmake ..

make

./bin/tests
