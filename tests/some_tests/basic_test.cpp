#include <gtest/gtest.h>
#include "../src/MyString.h"

TEST(BasicTest, test_eq){
  EXPECT_EQ(1, 1);
}

TEST(BasicTest, TestName){
  //EXPECT_STREQ("abc", MyString("abc").c_str());
}
