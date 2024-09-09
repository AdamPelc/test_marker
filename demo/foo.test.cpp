#include "foo.hpp"

#include <gtest/gtest.h>

TEST(Foo, Call) {
    foo();
    ASSERT_TRUE(true);
}

TEST(Bar, Call) {
    bar();
    ASSERT_TRUE(true);
}

TEST(FooBar, CallBoth) {
    foo();
    bar();
    ASSERT_TRUE(true);
}
