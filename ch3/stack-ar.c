#include <stack-ar.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define stk_top(stk) (*((int *)(stk->buf) + stk->top))

int stkar_push(struct stack_ar *stk, int d)
{
	if (stk->top >= stk->size) {
		stk_debug("stack is full\n");
		return -1;
	}
	stk->top++;
	stk_top(stk) = d;
	return 0;
}

int stkar_pop(struct stack_ar *stk, int *d)
{
	if (stkar_isempty(stk)) {
		stk_debug("stack is empty\n");
		return -1;
	}
	if (d)
		*d = stk_top(stk);
	stk->top--;
}

int stkar_isempty(struct stack_ar *stk)
{
	return (stk->top < 0) ? 1 : 0;
}

void stkar_clear(struct stack_ar *stk)
{
	if (!stkar_isempty(stk)) {
		stk->top = -1;
		memset(stk->buf, 0, stk->size);
	}
}

void stkar_top(struct stack_ar *stk, int *top)
{
	if(top)
		*top = stk_top(stk);
}

void stkar_destroy(struct stack_ar *stk)
{
	void *pbuf = stk->buf;

	free(pbuf);
	free(stk);
}

void stkar_debug(struct stack_ar *stk)
{
	stk_debug("stack: buf: %p, top: %d, size: %d\n",
		stk->buf, stk->top, stk->size);
}

struct stack_ar *stkar_create(int bytes)
{
	struct stack_ar *stk;
	void *pbuf;

	stk = malloc(sizeof(struct stack_ar));
	if (!stk) {
		stk_debug("malloc stk failed\n");
		return NULL;
	}

	pbuf = malloc(sizeof(char) * bytes);
	if (!pbuf) {
		free(stk);
		stk_debug("malloc pbuf failed\n");
		return NULL;
	}

	memset(pbuf, 0, bytes);
	stk->buf = pbuf;
	return stk;
}

int stkar_test(void)
{
	return 0;
}
