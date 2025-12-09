cmake_minimum_required(VERSION 4.0)
project(PZ_0_structure)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(PZ_0_structure
        func.cpp
        func.h
        main.cpp
        structs.h)
