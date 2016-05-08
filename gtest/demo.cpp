#include <iostream>
#include <gtest/gtest.h>
using namespace std;

int Foo(int a, int b){
	if (a == 0 || b == 0){
	throw "don't do that";
	}
	int c = a % b;
	if (c == 0)
	return b;
	return Foo(b, c);
}

int add(int a,int b){
	return a+b;
}

TEST(FooTest, HandleNoneZeroInput){
	EXPECT_EQ(2, Foo(4, 10));
	EXPECT_EQ(6, Foo(30, 18));
}

TEST(addTest,sumFunc){
	EXPECT_EQ(14, add(4, 10));
	EXPECT_EQ(6, add(30, 18));
}

int main(int argc, char* argv[]){

	testing::GTEST_FLAG(output) = "xml";
	testing::InitGoogleTest(&argc, argv);
	RUN_ALL_TESTS();
	getchar();

	return 0;
}

