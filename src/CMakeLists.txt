# test_marker library
add_library(test_marker STATIC)
target_sources(test_marker PRIVATE test_marker.cpp)
target_link_libraries(test_marker PRIVATE Boost::regex Boost::stacktrace_backtrace)
target_include_directories(test_marker PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_subdirectory(ut)
