#include <stdio.h>
#include <stdlib.h>
#include <runxian/test.h>
#include <stdint.h>

int32_t add(int32_t a, int32_t b) {
	return a + b;
}

TEST(testFunc,add) {
	EXPECT_EQ(add(5,3), 8);	
	EXPECT_EQ(add(5,3), 9);
	EXPECT_EQ(add(6,7), 9);
}

TEST(testFunc,add2) {
	EXPECT_EQ(add(5,3), 8);
	EXPECT_EQ(add(5,3), 9);
	EXPECT_EQ(add(6,7), 9);
}


TEST(test,Funcadd) {
	EXPECT_EQ(add(5,3), 8);
	EXPECT_EQ(add(5,3), 9);
	EXPECT_EQ(add(6,7), 9);
}

int32_t main(int32_t argc, char *argv[]) {
	return RUN_ALL_TESTS();
}
