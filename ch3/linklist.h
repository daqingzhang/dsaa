#ifndef __LINK_LIST_H__
#define __LINK_LIST_H__
#include <debug.h>

#ifdef DEBUG
#define ll_debug ioprintf
#else
#define ll_debug(...) do{}while(0)
#endif

#define ll_printf ioprintf

struct node {
	int d;
	struct node *p;
	struct node *n;
};

void ll_init(struct node *n);
void ll_show(struct node *n);
void ll_insert(struct node *p, struct node *n, struct node *c);
void ll_delete(struct node *n);
void ll_list(struct node *l);
void ll_destroy(struct node *l);
struct node *ll_create(int cnt);

int ll_test(void);

#endif
