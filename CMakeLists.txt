cmake_minimum_required(VERSION 3.28)
project(Network)

set(CMAKE_CXX_STANDARD 17)

add_executable(Network
        src/main.cpp
        src/Layer.cpp
        header/Layer.h
        header/Math.h
        src/Network.cpp
        header/Network.h
        src/DataReader.cpp
        header/DataReader.h
        header/Operations/Operation.h
        src/Operations/WeightMultiply.cpp
        header/Operations/WeightMultiply.h
        src/Operations/BiasAdd.cpp
        header/Operations/BiasAdd.h
        src/Operations/Sigmoid.cpp
        header/Operations/Sigmoid.h
        src/Operations/Loss.cpp
        header/Operations/Loss.h
        src/Operations/Operation.cpp
)

file(COPY data/numbers DESTINATION ${CMAKE_BINARY_DIR})