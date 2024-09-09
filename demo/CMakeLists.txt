cmake_minimum_required(VERSION 3.25)
project(test_checkpoint.demo)

set(CMAKE_CXX_STANDARD 20)

find_package(trick REQUIRED)

include(CMakePrintHelpers)
message("CMAKE_PREFIX_PATH: ${CMAKE_PREFIX_PATH}")
message("TRICK_FOUND: ${trick_FOUND}")
cmake_print_properties(TARGETS trick::test_checkpoint PROPERTIES
    IMPORTED_CONFIGURATION
    INTERFACE_INCLUDE_DIRECTORIES
)
