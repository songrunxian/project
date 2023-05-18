#include <stdio.h>
#include <stdlib.h>
#include <runxian/test.h>
#include <stdint.h>

int32_t add(int32_t a, int32_t b) {
	return a + b;
}

//TSET_是一个测试用例，我们生成测试用例，然后在里面生成测试点，对C语言函数进行测试
TEST(testFunc, add) {
	EXPECT_EQ(add(5,3), 8);	//测试点
	EXPECT_EQ(add(5,3), 9);
	EXPECT_EQ(add(5,3), 9);
}

TEST(testFunc, add2) {
	EXPECT_EQ(add(5,3), 8);
	EXPECT_EQ(add(5,3), 9);
	EXPECT_EQ(add(5,7), 9);
}

int32_t main(int32_t argc, char *argv[]) {
	return RUN_ALL_TESTS();
}
