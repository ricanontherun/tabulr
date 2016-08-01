cmake_minimum_required(VERSION 2.8.7)
project(tests)

set(CMAKE_CXX_COMPILER g++)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -std=c++14 -Werror -Wall")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY bin)

include_directories(../include)

set(SOURCES
    TestCell.cpp
    TestRow.cpp
    TestTable.cpp
    TestFormat.cpp
    ../source/tabulr/row.cpp
    ../source/tabulr/table.cpp
)

add_executable(tests ${SOURCES})
