#!/bin/bash

# GooseCrypto Test Runner

echo "Running GooseCrypto Tests..."

# Build the project first
echo "Building project..."
make clean
make

# Check if build was successful
if [ $? -ne 0 ]; then
    echo "Build failed. Cannot run tests."
    exit 1
fi

# Run C++ tests
echo "Running C++ tests..."

echo "Running Block tests..."
make test-block
if [ $? -ne 0 ]; then
    echo "Block tests failed."
    exit 1
fi

echo "Running Blockchain tests..."
make test-blockchain
if [ $? -ne 0 ]; then
    echo "Blockchain tests failed."
    exit 1
fi

echo "Running Wallet tests..."
make test-wallet
if [ $? -ne 0 ]; then
    echo "Wallet tests failed."
    exit 1
fi

echo "Running Crypto tests..."
make test-crypto
if [ $? -ne 0 ]; then
    echo "Crypto tests failed."
    exit 1
fi

echo "All C++ tests passed!"

# Run JavaScript tests
echo "Running JavaScript tests..."
cd api/javascript
npm test
if [ $? -ne 0 ]; then
    echo "JavaScript tests failed."
    exit 1
fi

echo "All tests passed successfully!"