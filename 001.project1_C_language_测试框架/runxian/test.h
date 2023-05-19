#ifndef _TEST_H
#define _TEST_H

#include <stdint.h>

#define TEST(a, b) void a##_runxian_##b(); \
       __attribute__((constructor)) \
       void add##_runxian_##a##_runxian_##b(){ \
	       add_function(a##_runxian_##b, #a "xian" #b); \
       }\
       void a##_runxian_##b()

#define EXPECT_EQ(a, b) printf("%s == %s ? %s\n", #a, #b, (a)== (b) ? "TRUE" : "FALSE");

typedef void (*TestFuncT) ();

struct Node{
	TestFuncT func;
	const char * str;
};

int32_t RUN_ALL_TESTS();
void add_function(TestFuncT, const char *);

#endif
