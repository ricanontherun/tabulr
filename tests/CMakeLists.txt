cmake_minimum_required(VERSION 2.8.12)
project(tests)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -Werror -Wall")

set(SOURCES
    TestColumn.cpp
)

include_directories(../include)

add_executable(tests ${SOURCES})
