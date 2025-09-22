#!/bin/bash

# GooseCrypto Build Script

echo "Building GooseCrypto Node..."

# Create build directory
mkdir -p build
cd build

# Configure with CMake
cmake ..

# Build the project
make

echo "Build complete!"
echo "To run the node, execute: ./build/goosecrypto_node"