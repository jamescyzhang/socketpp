cmake_minimum_required(VERSION 3.10)
project(socketpp)

set(CMAKE_CXX_STANDARD 11)

add_library(socketpp src/net/node.cpp src/net/node.hpp src/net/utils.hpp
        src/tcp/tcp_server.cpp src/tcp/tcp_server.hpp
        src/tcp/tcp_client.cpp src/tcp/tcp_client.hpp)

include_directories(src)

install(TARGETS socketpp
        DESTINATION ${CMAKE_SOURCE_DIR}/dist)

install(DIRECTORY src/ DESTINATION ${CMAKE_SOURCE_DIR}/dist/include
        FILES_MATCHING PATTERN "*.hpp")