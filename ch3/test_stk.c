#include <stack-comm.h>

int stk_test(void)
{
	int d;
	stack_t *stk;

	stk = stk_create(10);
	stk_debug(stk);

	stk_push(stk, 0xaa);
	stk_push(stk, 0xbb);
	stk_debug(stk);

	stk_pop(stk, &d);
	stk_debug(stk);
	printf("after pop 1, d: %x\n", d);

	stk_pop(stk, &d);
	stk_debug(stk);
	printf("after pop 2, d: %x\n", d);

	stk_push(stk, 0xcc);
	stk_push(stk, 0xdd);
	stk_pop(stk, &d);
	printf("after pop, d: %x\n", d);
	stk_debug(stk);
	
	stk_push(stk, 0x1);
	stk_push(stk, 0x2);
	stk_push(stk, 0x3);
	stk_push(stk, 0x4);
	stk_push(stk, 0x5);
	stk_push(stk, 0x6);
	stk_push(stk, 0x7);
	stk_push(stk, 0x8);
	stk_push(stk, 0x9);
	stk_push(stk, 0x10);
	stk_push(stk, 0x11);
	stk_push(stk, 0x12);
	stk_debug(stk);
	return 0;
}
