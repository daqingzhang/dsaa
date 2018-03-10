#ifndef __STACK_LL_H__
#define __STACK_LL_H__
#include <linklist.h>

struct stack_ll {
	struct node *list;
	struct node *top;
	unsigned int cnt;
	unsigned int size;
};

typedef struct stack_ll stack_t;

int  stkll_push(stack_t *stk, int d);
int  stkll_pop(stack_t *stk, int *d);
int  stkll_isempty(stack_t *stk);
void stkll_clear(stack_t *stk);
void stkll_top(stack_t *stk, int *top);
void stkll_destroy(stack_t *stk);
void stkll_debug(stack_t *stk);
stack_t *stkll_create(int size);

int stkll_test(void);

#endif
