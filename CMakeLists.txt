cmake_minimum_required(VERSION 3.15)
project(LRUSimulate)

set(CMAKE_CXX_STANDARD 17)

add_executable(LRUSimulate run.cpp lruclass.hpp execution.hpp)
