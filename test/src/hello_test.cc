#include "hello.h"

#include "gtest/gtest.h"

// test class1 here
// // ...
namespace {
  class HelloTest : public ::testing::Test {
  protected:
     hello myhello;
  };
  TEST_F(HelloTest, hello123) {
    ASSERT_TRUE(myhello.check());
  }
}
