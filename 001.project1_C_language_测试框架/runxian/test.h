#ifndef _TEST_H
#define _TEST_H

#include <stdint.h>

#define TEST(a,b) void a##b()			
//a##b()这样是定义可变函数名，不然宏一旦展开，会出现多个同名函数
#define EXPECT_EQ(a, b) printf("%s == %s ? %s\n", #a, #b, (a)== (b) ? "TRUE" : "FALSE");

int32_t RUN_ALL_TESTS();

#endif
