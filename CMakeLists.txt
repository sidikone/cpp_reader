cmake_minimum_required(VERSION 3.5)

project(file_reader LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


set(sources
    main.cpp
    csvreader.cpp
    csvwriter.cpp
    filwriter.cpp
    filreader.cpp
    display.cpp)

add_library(mycsvr SHARED IMPORTED GLOBAL
    csvreader.h
    csvwriter.h
    display.h
    csvreader.cpp
    csvwriter.cpp
    display.cpp)


add_executable(file_reader ${sources})

