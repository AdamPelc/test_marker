cmake_minimum_required(VERSION 3.25)
project(test_marker)

set(CMAKE_CXX_STANDARD 20)

enable_testing()

include(cmake/compiler_warnings.cmake)

find_package(Boost REQUIRED COMPONENTS regex stacktrace_backtrace)
find_package(GTest CONFIG REQUIRED)

add_library(test_checkpoint SHARED)
target_link_libraries(test_checkpoint
    PRIVATE
    compiler_warnings
    Boost::regex
    Boost::stacktrace_backtrace
)
target_include_directories(test_checkpoint PUBLIC include)

add_executable(test_checkpoint.test)
add_test(NAME test_checkpoint.test COMMAND test_checkpoint.test)
target_link_libraries(test_checkpoint.test
    PRIVATE
    compiler_warnings
    test_checkpoint
    GTest::gtest
    GTest::gtest_main
)

add_subdirectory(src)
