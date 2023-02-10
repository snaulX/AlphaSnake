cmake_minimum_required(VERSION 3.14)
project(AlphaSnake)

set(CMAKE_CXX_STANDARD 17)

set(SOURCES main.cpp)

add_executable(AlphaSnake ${SOURCES})

add_subdirectory(AlphaEngine)
add_subdirectory(RenderSystem)

target_link_libraries(AlphaSnake PRIVATE AlphaEngine)
install_systems(AlphaSnake RenderSystem)