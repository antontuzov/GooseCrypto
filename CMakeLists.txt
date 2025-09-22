cmake_minimum_required(VERSION 3.10)
project(GooseCrypto VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find required packages
find_package(OpenSSL REQUIRED)
find_package(Boost REQUIRED COMPONENTS system)
find_package(PkgConfig REQUIRED)

# Try to find Crow
pkg_check_modules(CROW crow)

# If Crow is not found via pkg-config, you might need to set it manually
if(NOT CROW_FOUND)
    # You may need to adjust this path based on your Crow installation
    set(CROW_INCLUDE_DIRS "/usr/local/include")
endif()

# Include directories
include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${OPENSSL_INCLUDE_DIRS}
    ${Boost_INCLUDE_DIRS}
    ${CROW_INCLUDE_DIRS}
)

# Source files
file(GLOB_RECURSE SOURCES "src/*.cpp")

# Create library
add_library(goosecrypto_lib ${SOURCES})
target_link_libraries(goosecrypto_lib 
    ${OPENSSL_LIBRARIES}
    ${Boost_LIBRARIES}
)

# Create executable
add_executable(goosecrypto_node src/main.cpp)
target_link_libraries(goosecrypto_node goosecrypto_lib)

# Installation rules
install(TARGETS goosecrypto_lib DESTINATION lib)
install(TARGETS goosecrypto_node DESTINATION bin)

# Install headers
install(DIRECTORY include/ DESTINATION include/goosecrypto
    FILES_MATCHING PATTERN "*.h"
)

# Tests
enable_testing()
find_package(GTest REQUIRED)

add_executable(block_test tests/block_test.cpp)
target_link_libraries(block_test goosecrypto_lib GTest::GTest GTest::Main)
add_test(NAME BlockTest COMMAND block_test)

add_executable(blockchain_test tests/blockchain_test.cpp)
target_link_libraries(blockchain_test goosecrypto_lib GTest::GTest GTest::Main)
add_test(NAME BlockchainTest COMMAND blockchain_test)