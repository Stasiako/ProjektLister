cmake_minimum_required(VERSION 3.15)
project(lister)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(lister
        line.cpp
        line.h
        lister.cpp
        word.cpp
        word.h)
