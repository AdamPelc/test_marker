# test_marker library
add_library(test_marker STATIC)
target_sources(test_marker PRIVATE test_marker.cpp)
target_link_libraries(test_marker PRIVATE boost_stacktrace_backtrace boost_regex)
target_include_directories(test_marker PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# test_marker tests
add_executable(test_marker.test)
add_test(NAME test_marker.test COMMAND test_marker.test)
target_link_libraries(test_marker.test PRIVATE gtest gtest_main test_marker Boost::regex)

add_subdirectory(ut)
