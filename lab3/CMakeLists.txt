cmake_minimum_required(VERSION 3.10)

project(LabProject)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(
    GLOB_RECURSE SOURCES
    src/*.h
    src/*.cpp
)

file(
    GLOB_RECURSE TESTS
    tests/*.h
    tests/*.cpp
)

add_executable(lab ${SOURCES})
target_include_directories(lab PUBLIC src)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

enable_testing()

list(REMOVE_ITEM SOURCES "${CMAKE_SOURCE_DIR}/src/main.cpp")

add_executable(runTests ${SOURCES} ${TESTS})
target_include_directories(runTests PUBLIC src)
target_link_libraries(runTests GTest::GTest GTest::Main)

gtest_discover_tests(runTests)