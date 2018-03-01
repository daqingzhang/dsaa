#ifndef __STACK_LL_H__
#define __STACK_LL_H__
#include <debug.h>

#ifdef DEBUG
#define stk_debug ioprintf
#else
#define stk_debug do{}while(0)
#endif

struct stack_ll {
	struct node *list;
	struct node *top;
	unsigned int cnt;
	unsigned int size;
};

int  stkll_push(struct stack_ll *stk, int d);
int  stkll_pop(struct stack_ll *stk, int *d);
int  stkll_isempty(struct stack_ll *stk);
void stkll_clear(struct stack_ll *stk);
void stkll_top(struct stack_ll *stk, int *top);
void stkll_destroy(struct stack_ll *stk);
void stkll_debug(struct stack_ll *stk);
struct stack_ll *stkll_create(int size);

int stkll_test(void);

#endif
