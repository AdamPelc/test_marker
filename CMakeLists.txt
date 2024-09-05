cmake_minimum_required(VERSION 3.25)
project(test_marker)

set(CMAKE_CXX_STANDARD 20)

enable_testing()

find_package(boost_regex CONFIG REQUIRED)

add_subdirectory(src)
