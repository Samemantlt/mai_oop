cmake_minimum_required(VERSION 3.8)

set(This ExampleTests)

find_package(GTest REQUIRED)
include(GoogleTest)
include(CTest)

set(Sources
    tests.cpp
)

add_executable(${This} ${Sources})
target_link_libraries(${This} PUBLIC gtest::gtest gtest::main lab1)

add_test(
    NAME ${This}
    COMMAND ${This}
)