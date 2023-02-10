cmake_minimum_required(VERSION 3.14)
project(RenderSystem)

set(CMAKE_C_STANDARD 11)

set(SOURCES Source/RenderSystem.c)

add_library(RenderSystem SHARED ${SOURCES})

target_include_directories(RenderSystem PRIVATE Include/Private)
target_include_directories(RenderSystem PUBLIC Include/Public)
target_link_libraries(RenderSystem PUBLIC AlphaEngine)