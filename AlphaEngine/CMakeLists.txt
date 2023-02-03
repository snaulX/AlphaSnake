cmake_minimum_required(VERSION 3.14)
project(AlphaEngine)
include(Cmake/CPM.cmake)

set(CMAKE_CXX_STANDARD 17)

set(SOURCES Source/AlphaEngine.cpp)

add_library(AlphaEngine STATIC ${SOURCES})

target_include_directories(AlphaEngine PUBLIC Include)

function(install_systems TARGET_NAME SYSTEMS)
    foreach(SYSTEM ${SYSTEMS})
        add_custom_command(TARGET ${TARGET_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy_if_different
                $<TARGET_FILE:${SYSTEM}>
                "$<TARGET_FILE_DIR:${TARGET_NAME}>")
    endforeach()
endfunction()

add_subdirectory(Tangara)
target_link_libraries(AlphaEngine PUBLIC Tangara)