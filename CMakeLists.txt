cmake_minimum_required(VERSION 2.8.12)
project(tabulr)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -Werror -Wall")

set(SOURCES
    main.cpp 
    source/tabulr/table.cpp
    source/tabulr/row.cpp
)

include_directories(include)

add_executable(tabulr ${SOURCES})
