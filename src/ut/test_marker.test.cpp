#include "test_marker.h"

#include <gtest/gtest.h>

TEST(TestName, TestCaseName) {
    const auto [test_name, test_case_name] = trick::get_test_name().value();
    EXPECT_EQ("TestName", test_name);
    EXPECT_EQ("TestCaseName", test_case_name);
}

TEST(TestName, TC12345_TestCaseName) {
    const auto [test_name, test_case_name] = trick::get_test_name().value();
    EXPECT_EQ("TestName", test_name);
    EXPECT_EQ("TC12345_TestCaseName", test_case_name);
}

class TestFixture : public ::testing::Test {};

TEST_F(TestFixture, TestCaseName) {
    const auto [test_name, test_case_name] = trick::get_test_name().value();
    EXPECT_EQ("TestFixture", test_name);
    EXPECT_EQ("TestCaseName", test_case_name);
}

class TestFixtureName : public ::testing::TestWithParam<int> {
};

TEST_P(TestFixtureName, TestName) {
    const auto [test_name, test_case_name] = trick::get_test_name().value();
    EXPECT_EQ("TestFixtureName", test_name);
    EXPECT_EQ("TestName", test_case_name);
}

INSTANTIATE_TEST_CASE_P(Odd, TestFixtureName, ::testing::Values(1, 3, 5));
INSTANTIATE_TEST_CASE_P(Even, TestFixtureName, ::testing::Values(2, 4, 6));
