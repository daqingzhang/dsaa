#include <stack-ar.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <debug.h>

#define top_inc(stk)	(stk->top++)
#define top_dec(stk)	(stk->top--)
#define top_dat(stk)	(*((int *)(stk->buf) + stk->top))

int stkar_push(stack_t *stk, int d)
{
	if (stk->top >= stk->size) {
		DEBUG("stack is full\n");
		return -1;
	}
	top_inc(stk);
	top_dat(stk) = d;
	return 0;
}

int stkar_pop(stack_t *stk, int *d)
{
	if (stkar_isempty(stk)) {
		DEBUG("stack is empty\n");
		return -1;
	}
	if (d)
		*d = top_dat(stk);
	top_dec(stk);
}

int stkar_isempty(stack_t *stk)
{
	return (stk->top < 0) ? 1 : 0;
}

void stkar_clear(stack_t *stk)
{
	if (!stkar_isempty(stk)) {
		stk->top = -1;
		memset(stk->buf, 0, stk->size);
	}
}

void stkar_top(stack_t *stk, int *top)
{
	if(top)
		*top = top_dat(stk);
}

void stkar_destroy(stack_t *stk)
{
	void *pbuf = stk->buf;

	free(pbuf);
	free(stk);
}

void stkar_debug(stack_t *stk)
{
	DEBUG("stack: buf: %p, top: %d, size: %d\n",
		stk->buf, stk->top, stk->size);
}

static void stkar_init(stack_t *stk, void *buf, int len)
{
	stk->top = -1;
	stk->buf = buf;
	stk->size = len;
}

stack_t *stkar_create(int bytes)
{
	stack_t *stk;
	void *pbuf;

	stk = malloc(sizeof(stack_t));
	if (!stk) {
		DEBUG("malloc stk failed\n");
		return NULL;
	}

	pbuf = malloc(sizeof(char) * bytes);
	if (!pbuf) {
		free(stk);
		DEBUG("malloc pbuf failed\n");
		return NULL;
	}
	memset(pbuf, 0, bytes);
	stkar_init(stk, pbuf, bytes);
	return stk;
}
