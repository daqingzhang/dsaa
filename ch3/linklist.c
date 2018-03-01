#include <stdlib.h>
#include <linklist.h>

void ll_init(struct node *n)
{
	n->d = 0;
	n->p = n;
	n->n = n;
}

void ll_show(struct node *n)
{
	ll_printf("node[%p]: data = %x, previous = %p, next = %p\n",
		n, n->d, n->p, n->n);
}

void ll_insert(struct node *p, struct node *n, struct node *c)
{
	c->n = p->n;
	p->n = c;
	c->p = n->p;
	n->p = c;
}

void ll_delete(struct node *c)
{
	struct node *p = c->p;
	struct node *n = c->n;

	p->n = c->n;
	n->p = c->p;

	ll_debug("delete node %p\n", c);
	free(c);
}

void ll_list(struct node *l)
{
	struct node *p = l;

	do {
		ll_show(p);
		p = p->n;
	} while(p != l);
}

struct node *ll_create(int cnt)
{
	int i;
	struct node *head, *p, *c;

	c = (struct node *)malloc(sizeof(struct node));
	head = c;
	ll_init(head);
	p = head;
	head->d = 0;

	for(i = 0;i < cnt - 1; i++) {
		c = (struct node *)malloc(sizeof(struct node));
		ll_insert(p, p->n, c);
		p = p->n;
		p->d = i + 1;
	}
	ll_debug("create %d node, head is %p\n", cnt, head);
	return head;
}

void ll_destroy(struct node *l)
{
	struct node *p, *c;

	p = l;
	do {
		c = p;
		p = p->n;
		ll_debug("free node %p\n", c);
		free(c);
	} while (p != l);
}

int ll_test(void)
{
	struct node *head, *p, *c;

	head = ll_create(10);
	ll_list(head);

	c = head->n;
	ll_delete(c);
	ll_list(head);

	c = ll_create(1);
	p = head->n;
	ll_insert(p, p->n, c);
	ll_list(head);

	ll_destroy(head);

	return 0;
}
