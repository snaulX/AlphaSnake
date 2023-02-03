cmake_minimum_required(VERSION 3.14)
project(SnakeExe)

set(CMAKE_CXX_STANDARD 17)

set(SOURCES main.cpp)

add_executable(SnakeExe ${SOURCES})

target_link_libraries(SnakeExe PRIVATE AlphaEngine)