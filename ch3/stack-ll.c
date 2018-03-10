#include <stdio.h>
#include <stdlib.h>
#include <linklist.h>
#include <stack-ll.h>

#include <debug.h>

#define ll_walk_a(top)	(top->n)
#define ll_walk_b(top)	(top->p)
#define ll_data(top)	(top->d)

int stkll_push(stack_t *stk, int d)
{
	stk->cnt++;
	stk->top = ll_walk_a(stk->top);
	ll_data(stk->top) = d;

	return 0;
}

int stkll_pop(stack_t *stk, int *d)
{
	if(stkll_isempty(stk)) {
		DEBUG("cant pop empty stack\n");
		return -1;
	}

	if(d)
		*d = ll_data(stk->top);

	ll_data(stk->top) = 0;
	stk->cnt--;
	stk->top = ll_walk_b(stk->top);
}

int stkll_isempty(stack_t *stk)
{
	return (!stk->cnt);
}

void stkll_clear(stack_t *stk)
{
	stk->top = stk->list;
	stk->cnt = 0;
}

void stkll_top(stack_t *stk, int *top)
{
	if(top)
		*top = ll_data(stk->top);
}

stack_t *stkll_create(int size)
{
	struct node *h, *p;
	stack_t *stk;
	int i;

	stk = (stack_t *)malloc(sizeof(stack_t));
	if(!stk) {
		DEBUG("malloc stk failed\n");
		return NULL;
	}

	h = ll_create(1);
	ll_init(h);
	stk->list = h;

	for(i = 0;i < size; i++) {
		p = ll_create(1);
		ll_insert(h,h->n,p);
		h = h->n;
	}

	stk->cnt = 0;
	stk->size = size;
	stk->top = stk->list;

	DEBUG("%s, list: %p, top: %p, cnt: %d, size: %d\n",
		__func__, stk->list, stk->top, stk->cnt, stk->size);

	return stk;
}

void stkll_destroy(stack_t *stk)
{
	ll_destroy(stk->list);
	free(stk);
}

void stkll_debug(stack_t *stk)
{
	DEBUG("list: %p, top: %p, cnt: %d, size: %d\n",
		stk->list, stk->top, stk->cnt, stk->size);
	DEBUG("list stack:\n");
	ll_list(stk->list);
}
