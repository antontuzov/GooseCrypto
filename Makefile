# GooseCrypto Makefile

# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O2
INCLUDES = -Iinclude

# Try to find libraries
LIBS = -lssl -lcrypto

# Check if gtest is available by trying to compile a simple test
HAS_GTEST := $(shell echo '\#include <gtest/gtest.h>\nint main(){return 0;}' | $(CXX) -x c++ -o /dev/null - 2>/dev/null && echo YES || echo NO)

# Set gtest includes and libs based on availability
ifeq ($(HAS_GTEST),YES)
    GTEST_INCLUDES = -isystem /usr/local/include -isystem /opt/homebrew/include
    GTEST_LIBS = -lgtest -lgtest_main -lpthread
else
    GTEST_INCLUDES =
    GTEST_LIBS =
endif

# Source files
SOURCES = $(wildcard src/core/*.cpp) $(wildcard src/crypto/*.cpp) $(wildcard src/network/*.cpp) $(wildcard src/utils/*.cpp)
MAIN_SOURCE = src/main.cpp

# Object files
OBJECTS = $(SOURCES:.cpp=.o)
MAIN_OBJECT = $(MAIN_SOURCE:.cpp=.o)

# Target executable
TARGET = goosecrypto_node

# Default target
all: $(TARGET)

# Link the executable
$(TARGET): $(OBJECTS) $(MAIN_OBJECT)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LIBS)

# Compile source files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

# Clean build files
clean:
	rm -f $(OBJECTS) $(MAIN_OBJECT) $(TARGET) test-*

# Rebuild everything
rebuild: clean all

# Install dependencies (Ubuntu/Debian)
install-deps:
	sudo apt-get update
	sudo apt-get install -y build-essential cmake libssl-dev libgtest-dev

# Install dependencies (macOS with Homebrew)
install-deps-mac:
	brew install openssl cmake googletest

# Run the node
run: $(TARGET)
	./$(TARGET)

# Simple test that doesn't require Google Test
simple-test:
	$(CXX) $(CXXFLAGS) $(INCLUDES) -o simple-test tests/simple_test.cpp src/core/block.o src/core/blockchain.o src/core/transaction.o src/core/wallet.o src/crypto/keys.o src/crypto/sha256.o src/network/api_server.o src/network/p2p.o src/utils/config.o src/utils/logger.o $(LIBS)
	./simple-test

# Run tests (only if gtest is available)
ifeq ($(HAS_GTEST),YES)
test: test-block test-blockchain test-wallet test-crypto
else
test: simple-test
	@echo "Google Test not found. Ran simple test instead."
	@echo "To install Google Test:"
	@echo "  Ubuntu/Debian: sudo apt-get install libgtest-dev"
	@echo "  macOS: brew install googletest"
endif

test-block:
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(GTEST_INCLUDES) -o test-block tests/block_test.cpp src/core/block.o src/core/transaction.o src/crypto/sha256.o src/utils/logger.o $(GTEST_LIBS) $(LIBS)
	./test-block

test-blockchain:
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(GTEST_INCLUDES) -o test-blockchain tests/blockchain_test.cpp src/core/blockchain.o src/core/block.o src/core/transaction.o src/crypto/sha256.o src/core/wallet.o src/crypto/keys.o src/utils/logger.o $(GTEST_LIBS) $(LIBS)
	./test-blockchain

test-wallet:
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(GTEST_INCLUDES) -o test-wallet tests/wallet_test.cpp src/core/wallet.o src/crypto/keys.o src/crypto/sha256.o src/utils/logger.o $(GTEST_LIBS) $(LIBS)
	./test-wallet

test-crypto:
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(GTEST_INCLUDES) -o test-crypto tests/crypto_test.cpp src/crypto/sha256.o src/crypto/keys.o src/core/transaction.o src/utils/logger.o $(GTEST_LIBS) $(LIBS)
	./test-crypto

.PHONY: all clean rebuild install-deps install-deps-mac run test simple-test test-block test-blockchain test-wallet test-crypto