#include <stdio.h>
#include <stdlib.h>
#include <linklist.h>
#include <stack-ll.h>

#define ll_walk_a(top)	(top->n)
#define ll_walk_b(top)	(top->p)
#define ll_data(top)	(top->d)

int stkll_push(struct stack_ll *stk, int d)
{
	stk->cnt++;
	stk->top = ll_walk_a(stk->top);
	ll_data(stk->top) = d;

	return 0;
}

int stkll_pop(struct stack_ll *stk, int *d)
{
	if(stkll_isempty(stk)) {
		stk_debug("cant pop empty stack\n");
		return -1;
	}

	if(d)
		*d = ll_data(stk->top);

	ll_data(stk->top) = 0;
	stk->cnt--;
	stk->top = ll_walk_b(stk->top);
}

int stkll_isempty(struct stack_ll *stk)
{
	return (!stk->cnt);
}

void stkll_clear(struct stack_ll *stk)
{
	stk->top = stk->list;
	stk->cnt = 0;
}

void stkll_top(struct stack_ll *stk, int *top)
{
	if(top)
		*top = ll_data(stk->top);
}

struct stack_ll *stkll_create(int size)
{
	struct node *h, *p;
	struct stack_ll *stk;
	int i;

	stk = (struct stack_ll *)malloc(sizeof(struct stack_ll));
	if(!stk) {
		stk_debug("malloc stk failed\n");
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

	stk_debug("%s, list: %p, top: %p, cnt: %d, size: %d\n",
		__func__, stk->list, stk->top, stk->cnt, stk->size);

	return stk;
}

void stkll_destroy(struct stack_ll *stk)
{
	ll_destroy(stk->list);
	free(stk);
}

void stkll_debug(struct stack_ll *stk)
{
	stk_debug("list: %p, top: %p, cnt: %d, size: %d\n",
		stk->list, stk->top, stk->cnt, stk->size);
	stk_debug("list stack:\n");
	ll_list(stk->list);
}

int stkll_test(void)
{
	int d;
	struct stack_ll *stk;

	stk = stkll_create(10);
	stkll_debug(stk);

	stkll_push(stk, 0xaa);
	stkll_push(stk, 0xbb);
	stkll_debug(stk);

	stkll_pop(stk, &d);
	stkll_debug(stk);
	stk_debug("after pop 1, d: %x\n", d);

	stkll_pop(stk, &d);
	stkll_debug(stk);
	stk_debug("after pop 2, d: %x\n", d);

	stkll_push(stk, 0xcc);
	stkll_push(stk, 0xdd);
	stkll_pop(stk, &d);
	stk_debug("after pop, d: %x\n", d);
	stkll_debug(stk);
	
	stkll_push(stk, 0x1);
	stkll_push(stk, 0x2);
	stkll_push(stk, 0x3);
	stkll_push(stk, 0x4);
	stkll_push(stk, 0x5);
	stkll_push(stk, 0x6);
	stkll_push(stk, 0x7);
	stkll_push(stk, 0x8);
	stkll_push(stk, 0x9);
	stkll_push(stk, 0x10);
	stkll_push(stk, 0x11);
	stkll_push(stk, 0x12);
	stkll_debug(stk);
	return 0;
}
