#!/bin/bash

# GooseCrypto Run Script

echo "Starting GooseCrypto Node..."

# Check if build exists
if [ ! -f "./build/goosecrypto_node" ]; then
    echo "Node binary not found. Building first..."
    ./build.sh
fi

# Run the node
./build/goosecrypto_node