#include "test_marker.h"

#include <gtest/gtest.h>

TEST(TestName, TestCaseName) {
    const auto [test_name, test_case_name] = trick::get_test_name().value();
    ASSERT_EQ("TestName", test_name);
    ASSERT_EQ("TestCaseName", test_case_name);
}

TEST(TestName, TC12345_TestCaseName) {
    const auto [test_name, test_case_name] = trick::get_test_name().value();
    ASSERT_EQ("TestName", test_name);
    ASSERT_EQ("TC12345_TestCaseName", test_case_name);
}
