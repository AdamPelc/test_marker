cmake_minimum_required(VERSION 3.25)
project(test_checkpoint.demo)

set(CMAKE_CXX_STANDARD 20)

find_package(trick CONFIG REQUIRED)
find_package(GTest CONFIG REQUIRED)

include(CMakePrintHelpers)
message("CMAKE_PREFIX_PATH: ${CMAKE_PREFIX_PATH}")
message("TRICK_FOUND: ${trick_FOUND}")
cmake_print_properties(TARGETS trick::test_checkpoint PROPERTIES
    IMPORTED_CONFIGURATION
    INTERFACE_INCLUDE_DIRECTORIES
)

enable_testing()

# Production code
add_library(demo)
target_sources(demo
    PRIVATE foo.cpp
)
target_link_libraries(demo
    PRIVATE
    trick::test_checkpoint
)

# Test code
add_executable(demo.test)
add_test(NAME demo.test COMMAND demo.test)
target_sources(demo.test
    PRIVATE
    foo.test.cpp
)
target_link_libraries(demo.test
    PRIVATE
    demo
    GTest::gtest
    GTest::gtest_main
)
