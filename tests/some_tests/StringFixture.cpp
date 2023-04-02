#include <gtest/gtest.h>
#include "MyString.h"

class StringFixture : public ::testing::Test{

 protected:
  virtual void SetUp(){
	//q_0_ = MyString();
  }
 protected:
  MyString q_0_;
};

TEST_F(StringFixture, SimpleTest){
  q_0_ = MyString("abc");
  EXPECT_EQ(5, q_0_.size());
}
