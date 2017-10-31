#include "gtest/gtest.h"

#include "lib/greet.h"

TEST(test_hello, hello)
{
  EXPECT_EQ(testFunc(), 42);
}

