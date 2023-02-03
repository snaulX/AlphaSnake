cmake_minimum_required(VERSION 3.14)
project(Tangara)

set(CMAKE_CXX_STANDARD 17)

set(SOURCES Source/Heap.cpp Source/Type.cpp Source/Stack.cpp Source/Interface.cpp)

add_library(Tangara STATIC ${SOURCES})

target_include_directories(Tangara PRIVATE Include/Private)
target_include_directories(Tangara PUBLIC Include/Public)