#!/bin/bash

# Build project binary
cd build
cmake ..
make

# Build tests
cd ../tests/build
cmake ..
make

