#include "gtest/gtest.h"
#include "factory.hpp"

TEST(BasicTests, OneInput){
	char* test_val[2];
	test_val[0] = strdup("./calculator");
	test_val[1] = strdup("1");
	Factory test;
	EXPECT_EQ(nullptr, test.parse(test_val, 2));
}

TEST(BasicTests, TwoNumbers){
	char* test_val[3];
	test_val[0] = strdup("./calculator");
	test_val[1] = strdup("5");
	test_val[2] = strdup("6");
	Factory test;
	EXPECT_EQ(nullptr, test.parse(test_val, 3));
}

TEST(BasicTests, SimpleAdd){
	char* test_val[4];
	test_val[0] = strdup("./calculator");
	test_val[1] = strdup("3");
	test_val[2] = strdup("+");
	test_val[3] = strdup("9");
	Factory test;
	Base* capture = test.parse(test_val, 4);
	EXPECT_EQ(12, capture->evaluate());
	EXPECT_EQ("(3.000000+9.000000)", capture->stringify());
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
