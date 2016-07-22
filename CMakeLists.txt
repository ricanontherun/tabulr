cmake_minimum_required(VERSION 2.8.7)
project(tabulr)

set(CMAKE_CXX_COMPILER g++)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -c -std=c++14 -Werror -Wall")
set(EXECUTABLE_OUTPUT_PATH bin)
set(LIBRARY_OUTPUT_PATH build)

include_directories(include)

set(SOURCES
    source/tabulr/table.cpp
    source/tabulr/row.cpp
)

add_executable(tabulr ${SOURCES})
