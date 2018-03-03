#ifndef __STACK_AR_H__
#define __STACK_AR_H__
#include <debug.h>

#ifdef DEBUG
#if !defined(stk_debug)
#define stk_debug ioprintf
#endif
#else
#if !defined(stk_debug)
#define stk_debug do{}while(0)
#endif
#endif

#define STACK_SIZE (8 * 1024)

struct stack_ar {
	void *buf;
	int top;
	int size;
};

int  stkar_push(struct stack_ar *stk, int d);
int  stkar_pop(struct stack_ar *stk, int *d);
int  stkar_isempty(struct stack_ar *stk);
void stkar_clear(struct stack_ar *stk);
void stkar_top(struct stack_ar *stk, int *top);
void stkar_destroy(struct stack_ar *stk);
void stkar_debug(struct stack_ar *stk);
struct stack_ar *stkar_create(int size);

int stkar_test(void);

#endif
