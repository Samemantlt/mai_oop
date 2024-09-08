cmake_minimum_required(VERSION 3.10)

project(lab1 C CXX)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

enable_testing()

find_package(GTest REQUIRED)
include(GoogleTest)
include(CTest)

file(
    GLOB_RECURSE SOURCES
    src/*.h
    src/*.cpp
    tests/*.h
    tests/*.cpp
)

file(
    GLOB_RECURSE GTESTS
)

add_library(lab1 STATIC ${SOURCES})

add_subdirectory(tests)