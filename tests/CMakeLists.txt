cmake_minimum_required(VERSION 2.8.12)
project(tests)

set(CMAKE_CXX_COMPILER g++)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -Werror -Wall")

include_directories(../include)

set(SOURCES
    TestCell.cpp
    TestRow.cpp
    ../source/tabulr/row.cpp
)

add_executable(tests ${SOURCES})
