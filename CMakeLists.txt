cmake_minimum_required(VERSION 3.25)
project(test_marker)

set(CMAKE_CXX_STANDARD 20)

enable_testing()

include(cmake/compiler_warnings.cmake)

find_package(Boost REQUIRED COMPONENTS regex stacktrace_backtrace)
find_package(GTest CONFIG REQUIRED)

add_subdirectory(src)
