#!/bin/bash

if [ -d "build" ]; then
    rm -rf build
fi

mkdir build
cd build
cmake ..
make

echo ""
echo "Build complete. Running the program:"
echo "v---v---v---v---v---v---v---v---v---"
./MinimalCpp

