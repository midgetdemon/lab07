#include "gtest/gtest.h"
#include "factory.hpp"

TEST(NullTests, OneInput){
	char* test_val[2];
	test_val[0] = strdup("./calculator");
	test_val[1] = strdup("1");
	Factory test;
	EXPECT_EQ(nullptr, test.parse(test_val, 2));
}

TEST(NullTests, TwoNumbers){
	char* test_val[3];
	test_val[0] = strdup("./calculator");
	test_val[1] = strdup("5");
	test_val[2] = strdup("6");
	Factory test;
	EXPECT_EQ(nullptr, test.parse(test_val, 3));
}

TEST(NullTests, NumberandOp){
	char* test_val [3];
	test_val[0] = strdup("./calculator");
	test_val[1] = strdup("5");
	test_val[2] = strdup("-");
	Factory test;
	EXPECT_EQ(nullptr, test.parse(test_val, 3));
}

TEST(NullTests, DoubleOp){
	char* test_val [3];
        test_val[0] = strdup("./calculator");
        test_val[1] = strdup("*");
        test_val[2] = strdup("-");
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

TEST(BasicTests, SimpleSub){
        char* test_val[4];
        test_val[0] = strdup("./calculator");
        test_val[1] = strdup("6");
        test_val[2] = strdup("-");
        test_val[3] = strdup("5");
        Factory test;
        Base* capture = test.parse(test_val, 4);
        EXPECT_EQ(1, capture->evaluate());
        EXPECT_EQ("(6.000000-5.000000)", capture->stringify());
}

TEST(BasicTests, SimpleMult){
        char* test_val[4];
        test_val[0] = strdup("./calculator");
        test_val[1] = strdup("7");
        test_val[2] = strdup("*");
        test_val[3] = strdup("4");
        Factory test;
        Base* capture = test.parse(test_val, 4);
        EXPECT_EQ(28, capture->evaluate());
        EXPECT_EQ("(7.000000*4.000000)", capture->stringify());
}

TEST(BasicTests, SimpleDiv){
        char* test_val[4];
        test_val[0] = strdup("./calculator");
        test_val[1] = strdup("9");
        test_val[2] = strdup("/");
        test_val[3] = strdup("3");
        Factory test;
        Base* capture = test.parse(test_val, 4);
        EXPECT_EQ(3, capture->evaluate());
        EXPECT_EQ("(9.000000/3.000000)", capture->stringify());
}

TEST(BasicTests, SimplePow){
        char* test_val[4];
        test_val[0] = strdup("./calculator");
        test_val[1] = strdup("2");
        test_val[2] = strdup("**");
        test_val[3] = strdup("4");
        Factory test;
        Base* capture = test.parse(test_val, 4);
        EXPECT_EQ(16, capture->evaluate());
        EXPECT_EQ("(2.000000**4.000000)", capture->stringify());
}
/**

TEST(BasicTests, SimpleRandAdd){
        char* test_val[2];
        test_val[0] = strdup("./calculator");
	Rand* rand = new Rand(); 
	std::string str = rand->stringify();
	const char * c = str.c_str(); 
        test_val[1] = strdup(c); 
       // test_val[2] = strdup("+");
        //test_val[3] = strdup("1");
        Factory test;
        Base* capture = test.parse(test_val, 2);
        EXPECT_EQ(nullptr, capture->evaluate());
        //EXPECT_EQ(capture->stringify(), std::to_string(capture->evaluate()));
}
**/
TEST(RandTest, EvaluateRand){
	Rand* test = new Rand();
	EXPECT_EQ(test->evaluate(), test->evaluate());
}

TEST(RandTest, StringRand){
	Rand* test = new Rand();
	EXPECT_EQ(test->stringify(), std::to_string(test->evaluate()));
}

TEST(UserTests, Complex1){
        char* test_val[6];
        test_val[0] = strdup("./calculator");
        test_val[1] = (char*)"2";
        test_val[2] = (char*)"+";
        test_val[3] = (char*)"4";
	test_val[4] = (char*)"*";
	test_val[5] = (char*)"3"; 
        Factory test;
        Base* capture = test.parse(test_val, 6);
	//EXPECT_EQ(nullptr, test.parse(test_val, 6)); 
        EXPECT_EQ(18, capture->evaluate());
        EXPECT_EQ("((2.000000+4.000000)*3.000000)", capture->stringify());
}


TEST(UserTests, Complex2){
        char* test_val[6];
        test_val[0] = strdup("./calculator");
        test_val[1] = strdup("4");
        test_val[2] = strdup("*");
        test_val[3] = strdup("3");
        test_val[4] = strdup("/");
        test_val[5] = strdup("2");
        Factory test;
        Base* capture = test.parse(test_val, 6);
        EXPECT_EQ(6, capture->evaluate());
        EXPECT_EQ("((4.000000*3.000000)/2.000000)", capture->stringify());
}

TEST(UserTests, Complex3){
        char* test_val[6];
        test_val[0] = strdup("./calculator");
        test_val[1] = strdup("9");
        test_val[2] = strdup("-");
        test_val[3] = strdup("5");
        test_val[4] = strdup("/");
        test_val[5] = strdup("2");
        Factory test;
        Base* capture = test.parse(test_val, 6);
        EXPECT_EQ(2, capture->evaluate());
        EXPECT_EQ("((9.000000-5.000000)/2.000000)", capture->stringify());
}

TEST(UserTests, Complex4){
        char* test_val[8];
        test_val[0] = strdup("./calculator");
        test_val[1] = strdup("1");
        test_val[2] = strdup("+");
        test_val[3] = strdup("2");
        test_val[4] = strdup("*");
        test_val[5] = strdup("3");
	test_val[6] = strdup("-");
	test_val[7] = strdup("4");
        Factory test;
        Base* capture = test.parse(test_val, 8);
        EXPECT_EQ(5, capture->evaluate());
        EXPECT_EQ("(((1.000000+2.000000)*3.000000)-4.000000)", capture->stringify());
}

TEST(UserTests, Complex5){
        char* test_val[8];
        test_val[0] = strdup("./calculator");
        test_val[1] = strdup("5");
        test_val[2] = strdup("*");
        test_val[3] = strdup("2");
        test_val[4] = strdup("/");
        test_val[5] = strdup("2");
        test_val[6] = strdup("+");
        test_val[7] = strdup("100");
        Factory test;
        Base* capture = test.parse(test_val, 8);
        EXPECT_EQ(105, capture->evaluate());
        EXPECT_EQ("(((5.000000*2.000000)/2.000000)+100.000000)", capture->stringify());
}

int main (int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
