#ifndef __STACK_AR_H__
#define __STACK_AR_H__

#define STACK_SIZE (8 * 1024)

struct stack_ar {
	void *buf;
	int top;
	int size;
};

typedef struct stack_ar stack_t;

int  stkar_push(stack_t *stk, int d);
int  stkar_pop(stack_t *stk, int *d);
int  stkar_isempty(stack_t *stk);
void stkar_clear(stack_t *stk);
void stkar_top(stack_t *stk, int *top);
void stkar_destroy(stack_t *stk);
void stkar_debug(stack_t *stk);
stack_t *stkar_create(int size);

int stkar_test(void);

#endif
