cmake_minimum_required(VERSION 3.28)
project(test_marker)

set(CMAKE_CXX_STANDARD 20)

add_executable(test_marker library.cpp)
target_link_libraries(test_marker PRIVATE gtest gtest_main boost_stacktrace_backtrace boost_regex)
