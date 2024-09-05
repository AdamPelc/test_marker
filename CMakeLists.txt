cmake_minimum_required(VERSION 3.25)
project(test_marker)

set(CMAKE_CXX_STANDARD 20)

enable_testing()

find_package(Boost REQUIRED COMPONENTS regex)

add_subdirectory(src)
