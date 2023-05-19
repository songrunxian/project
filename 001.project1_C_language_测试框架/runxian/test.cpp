#include <string.h>
#include <stdio.h>
#include <stdint.h>
#include <runxian/test.h>
#include <math.h>

int32_t func_cnt = 0;
Node func_arr[100];

struct FunctionInfo test_info;

int32_t RUN_ALL_TESTS() {
	for (int32_t i = 0; i < func_cnt; i++) {
		printf( RED_HIGH("[=====Running=====]") YELLOW_HIGH(" %s\n"), func_arr[i].str );
		test_info.total = 0;
		test_info.success = 0;
		func_arr[i].func();
		double rate = 100.0 * test_info.success / test_info.total;
		printf(GREEN_HIGH("[  "));
		if(fabs(rate - 100.0) < 1e-6) {
			printf(BLUE_HIGH("%6.2lf%%"), rate);
		} else {
			printf(RED_HIGH("%6.2lf%%"), rate);
		}
		printf(
			GREEN("  ] ") "total : %d   success : %d\n",
			test_info.total,
			test_info.success
		);
		printf("Run end\n");
	}
	return 0;
}

void add_function(TestFuncT FUNC, const char *str) {
	func_arr[func_cnt].func = FUNC;
	func_arr[func_cnt].str = strdup(str);
        func_cnt++;
	return ;       
}
