add_executable(test_marker.test)
add_test(NAME test_marker.test COMMAND test_marker.test)
target_link_libraries(test_marker.test PRIVATE GTest::gtest GTest::gtest_main test_marker)
target_sources(test_marker.test PRIVATE test_marker.test.cpp)
