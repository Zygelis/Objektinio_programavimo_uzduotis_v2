cmake_minimum_required(VERSION 3.10)

project(OOP_projektas)

set(CMAKE_CXX_STANDARD 11)

set(SOURCES
    main.cpp
    vector.cpp
    list.cpp
    funkcijos.cpp
    funkcijos_list.cpp
    ivestis.cpp
    ivestis_list.cpp
)

include_directories(headers)

add_executable(MyExecutable ${SOURCES})