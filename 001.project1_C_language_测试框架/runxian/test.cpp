#include <string.h>
#include <stdio.h>
#include <stdint.h>
#include <runxian/test.h>

int32_t func_cnt = 0;
Node func_arr[100];

int32_t RUN_ALL_TESTS() {
	for (int32_t i = 0; i < func_cnt; i++) {
		printf( RED_HIGH("[=====Running=====]") YELLOW_HIGH(" %s\n"), func_arr[i].str );
		func_arr[i].func();
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
