cmake_minimum_required(VERSION 3.15)
project(LRU-Algorithm)

set(CMAKE_CXX_STANDARD 17)

add_executable(LRU-Algorithm run.cc lruclass.h lruclass.cc execution.h execution.cc)
