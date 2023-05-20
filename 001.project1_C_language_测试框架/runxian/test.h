#ifndef _TEST_H
#define _TEST_H

#include <stdint.h>

#define COLOR(a, b) "\033[" #b "m" a "\033[0m"
#define GREEN(a) COLOR(a, 32)
#define RED(a) COLOR(a, 31)
#define BLUE(a) COLOR(a, 34)
#define YELLOW(a) COLOR(a, 33)
#define PURPLE(a) COLOR(a, 35)

#define COLOR_HIGH(a, b) "\033[1;" #b "m" a "\033[0m"
#define GREEN_HIGH(a) COLOR_HIGH(a, 32)
#define RED_HIGH(a) COLOR_HIGH(a, 31)
#define BLUE_HIGH(a) COLOR_HIGH(a, 34)
#define YELLOW_HIGH(a) COLOR_HIGH(a, 33)
#define PURPLE_HIGH(a) COLOR_HIGH(a, 35)

#define TEST(a, b) void a##_runxian_##b(); \
       __attribute__((constructor)) \
       void add##_runxian_##a##_runxian_##b(){ \
	       add_function(a##_runxian_##b, #a "." #b); \
       }\
       void a##_runxian_##b()

#define P(a, color) { \
    char frm[1000]; \
    sprintf(frm, color("%d"), a); \
    printf(frm, a); \
}

#define PS(a, color) { \
    char frm[1000]; \
    sprintf(frm, color("%s"), a); \
    printf(frm, a); \
}

#define EXPECT(a, b, comp) {\
	printf(GREEN("[-----------] ") #a " " #comp " " #b ); \
	__typeof(a) _a = (a); \
        __typeof(b) _b = (b); \
	test_info.total += 1; \
	if(_a comp _b) test_info.success += 1; else {\
		        printf("\n"); \
        		printf(PURPLE_HIGH("\t%s:%d: Failure\n"), __FILE__, __LINE__); \
        		printf(PURPLE_HIGH("\t\texpect" #a " " #comp " " #b " actual : ")); \
        		P(_a, PURPLE_HIGH); \
        		PS(" vs ", PURPLE_HIGH); \
        		P(_b, PURPLE_HIGH); \
        		printf("\n\n"); \
	}\
	printf(GREEN("[-----------] ") #a " " #comp " " #b ); \
	printf(" %s\n", (_a) comp (_b) ? GREEN_HIGH("true"): RED_HIGH("false")); \
}
#define EXPECT_EQ(a, b) EXPECT(a, b, ==)
#define EXPECT_LT(a, b) EXPECT(a, b, <)
#define EXPECT_LE(a, b) EXPECT(a, b, <=)
#define EXPECT_GT(a, b) EXPECT(a, b, >)
#define EXPECT_GE(a, b) EXPECT(a, b, >=)
#define EXPECT_NE(a, b) EXPECT(a, b, !=)

typedef void (*TestFuncT) ();

struct Node{
	TestFuncT func;
	const char * str;
};

struct FunctionInfo {
	int32_t total;
	int32_t success;
};
extern struct FunctionInfo test_info;

int32_t RUN_ALL_TESTS();
void add_function(TestFuncT, const char *);

#endif
