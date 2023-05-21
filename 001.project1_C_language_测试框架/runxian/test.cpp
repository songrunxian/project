#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <runxian/linklist.h>
#include <runxian/test.h>
#include <math.h>

struct Node func_head, *func_tail = &func_head;
struct FunctionInfo test_info;

int32_t RUN_ALL_TESTS() {
	for (struct LinkNode *p = func_head.p.next; p; p = p->next ) {
		struct Node *func = Head(p, struct Node, p);
		printf( RED_HIGH("[=====Running=====]") YELLOW_HIGH(" %s\n"), func->str );
		test_info.total = 0;
		test_info.success = 0;
		func->func();
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
		printf(RED_HIGH("[==========Run end==========]\n"));
		printf("\n");
	}
	return 0;
}

void add_function(TestFuncT FUNC, const char *str) {
	struct Node *temp = (struct Node *) calloc(1, sizeof(struct Node));
	temp->func = FUNC;
	temp->str = strdup(str);
	func_tail->p.next = &(temp->p);
	func_tail = temp;
	return ;       
}
