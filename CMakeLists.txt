cmake_minimum_required(VERSION 3.28)
project(Network)

set(CMAKE_CXX_STANDARD 17)

add_executable(Network
        src/main.cpp
        src/Layer.cpp
        src/Layer.h
        src/Math.h
        src/Network.cpp
        src/Network.h)
