cmake_minimum_required(VERSION 3.14)
project(AlphaSnake)

set(CMAKE_CXX_STANDARD 17)

set(SOURCES main.cpp)

add_executable(AlphaSnake ${SOURCES})

add_subdirectory(AlphaEngine)
add_subdirectory(RenderSystem)

target_link_libraries(AlphaSnake PRIVATE AlphaEngine)
install_systems(AlphaSnake RenderSystem)

add_custom_command(TARGET AlphaSnake POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${CMAKE_SOURCE_DIR}/Snake/Game.lua"
        "$<TARGET_FILE_DIR:AlphaSnake>/Game.lua")