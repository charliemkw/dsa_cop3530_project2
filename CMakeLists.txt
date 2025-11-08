cmake_minimum_required(VERSION 3.28)
project(dsa_cop3530_project2)

set(CMAKE_CXX_STANDARD 14)

include_directories(src)

add_executable(dsa_cop3530_project2
        src/main.cpp
        src/MinHeap.cpp
        src/MinHeap.h
        src/location.cpp
        src/location.h
        src/distance.cpp
        src/distance.h
        src/mergesort.cpp
        src/mergesort.h)
