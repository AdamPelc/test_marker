cmake_minimum_required(VERSION 3.25)
project(test_marker)

set(CMAKE_CXX_STANDARD 20)

enable_testing()

include(cmake/compiler_warnings.cmake)

find_package(Boost REQUIRED COMPONENTS regex stacktrace_backtrace)
find_package(GTest CONFIG REQUIRED)

add_library(test_checkpoint SHARED)
target_sources(test_checkpoint
    PUBLIC
        FILE_SET HEADERS
        BASE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}/include
        FILES include/trick/test_checkpoint/checkpoint.hpp
)
target_link_libraries(test_checkpoint
    PRIVATE
    compiler_warnings
    Boost::regex
    Boost::stacktrace_backtrace
)
target_include_directories(test_checkpoint
    PUBLIC
    "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>"
    "$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>"
)

add_executable(test_checkpoint.test)
add_test(NAME test_checkpoint.test COMMAND test_checkpoint.test)
target_link_libraries(test_checkpoint.test
    PRIVATE
    compiler_warnings
    test_checkpoint
    GTest::gtest
    GTest::gtest_main
)

include(GNUInstallDirs)
install(TARGETS test_checkpoint EXPORT trick_targets
    LIBRARY
    FILE_SET HEADERS
)
install(EXPORT trick_targets
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/trick/cmake
    NAMESPACE trick::
)
install(FILES "cmake/trick-config.cmake"
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/trick/cmake
)

add_subdirectory(src)
