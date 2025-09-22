cmake_minimum_required(VERSION 3.10)
project(GooseCrypto VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Explicitly set OpenSSL paths for Homebrew installation
set(OPENSSL_ROOT_DIR "/usr/local/opt/openssl@3")
set(OPENSSL_INCLUDE_DIR "/usr/local/opt/openssl@3/include")
set(OPENSSL_CRYPTO_LIBRARY "/usr/local/opt/openssl@3/lib/libcrypto.dylib")
set(OPENSSL_SSL_LIBRARY "/usr/local/opt/openssl@3/lib/libssl.dylib")

# Find required packages
find_package(OpenSSL REQUIRED)

# Explicitly set Boost paths for Homebrew installation
set(BOOST_ROOT "/usr/local/Cellar/boost/1.89.0.reinstall")
set(Boost_INCLUDE_DIR "/usr/local/Cellar/boost/1.89.0.reinstall/include")
set(Boost_LIBRARY_DIRS "/usr/local/Cellar/boost/1.89.0.reinstall/lib")

# Try to find Boost
find_package(Boost REQUIRED)

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
    ${OPENSSL_INCLUDE_DIR}
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

# Try to find GTest in standard locations
find_package(GTest QUIET)

# If not found, try to find it in Homebrew locations
if(NOT GTest_FOUND)
    find_path(GTEST_INCLUDE_DIRS gtest/gtest.h
        PATHS /usr/local/include /opt/homebrew/include
        NO_DEFAULT_PATH)
        
    find_library(GTEST_LIBRARIES gtest
        PATHS /usr/local/lib /opt/homebrew/lib
        NO_DEFAULT_PATH)
        
    find_library(GTEST_MAIN_LIBRARIES gtest_main
        PATHS /usr/local/lib /opt/homebrew/lib
        NO_DEFAULT_PATH)
        
    if(GTEST_INCLUDE_DIRS AND GTEST_LIBRARIES AND GTEST_MAIN_LIBRARIES)
        set(GTest_FOUND TRUE)
        set(GTEST_BOTH_LIBRARIES ${GTEST_LIBRARIES} ${GTEST_MAIN_LIBRARIES})
    endif()
endif()

if(GTest_FOUND)
    message(STATUS "Found GTest: ${GTEST_INCLUDE_DIRS}")
    
    add_executable(block_test tests/block_test.cpp)
    target_link_libraries(block_test goosecrypto_lib ${GTEST_BOTH_LIBRARIES})
    target_include_directories(block_test PRIVATE ${GTEST_INCLUDE_DIRS})
    add_test(NAME BlockTest COMMAND block_test)

    add_executable(blockchain_test tests/blockchain_test.cpp)
    target_link_libraries(blockchain_test goosecrypto_lib ${GTEST_BOTH_LIBRARIES})
    target_include_directories(blockchain_test PRIVATE ${GTEST_INCLUDE_DIRS})
    add_test(NAME BlockchainTest COMMAND blockchain_test)
else()
    message(WARNING "GTest not found. Tests will not be built.")
endif()