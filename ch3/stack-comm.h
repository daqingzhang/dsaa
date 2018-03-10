#ifndef __STACK_COMM_H__
#define __STACK_COMM_H__
#include <debug.h>
/*
 * Array Stack
 */
#if defined(CONFIG_USE_STKAR)
#include <stack-ar.h>

#define stk_push(stk, d)	stkar_push(stk, d)
#define stk_pop(stk, d)		stkar_pop(stk, d)
#define stk_isempty(stk)	stkar_isempty(stk)
#define stk_clear(stk)		stkar_clear(stk)
#define stk_top(stk)		stkar_top(stk)
#define stk_destroy(stk)	stkar_destroy(stk)
#define stk_debug(stk)		stkar_debug(stk)
#define stk_create(stk)		stkar_create(stk)

/*
 * Link List Stack
 */
#else
#include <stack-ll.h>

#define stk_push(stk, d)	stkll_push(stk, d)
#define stk_pop(stk, d)		stkll_pop(stk, d)
#define stk_isempty(stk)	stkll_isempty(stk)
#define stk_clear(stk)		stkll_clear(stk)
#define stk_top(stk)		stkll_top(stk)
#define stk_destroy(stk)	stkll_destroy(stk)
#define stk_debug(stk)		stkll_debug(stk)
#define stk_create(stk)		stkll_create(stk)

#endif

#endif
