#include <stdio.h>
#include <stdlib.h>

struct node {
	int d;
	struct node *p;
	struct node *n;
};

void init(struct node *l)
{
	l->d = 0;
	l->p = l;
	l->n = l;
}

void show(struct node *n)
{
	printf("node[%p]: data = %x, previous = %p, next = %p\n",
		n, n->d, n->p, n->n);
}

void insert(struct node *p, struct node *n, struct node *c)
{
	c->n = p->n;
	p->n = c;
	c->p = n->p;
	n->p = c;
}

void delete(struct node *c)
{
	struct node *p = c->p;
	struct node *n = c->n;

	p->n = c->n;
	n->p = c->p;

	printf("delete node %p\n", c);
	free(c);
}

void list(struct node *l)
{
	struct node *p = l;

	do {
		show(p);
		p = p->n;
	} while(p != l);
}

struct node *create(int cnt)
{
	int i;
	struct node *head, *p, *c;

	c = (struct node *)malloc(sizeof(struct node));
	head = c;
	init(head);
	p = head;
	head->d = 0;

	for(i = 0;i < cnt - 1; i++) {
		c = (struct node *)malloc(sizeof(struct node));
		insert(p, p->n, c);
		p = p->n;
		p->d = i + 1;
	}
	printf("create %d node, head is %p\n", cnt, head);
	return head;
}

void destroy(struct node *l)
{
	struct node *p, *c;

	p = l;
	do {
		c = p;
		p = p->n;
		printf("free node %p\n", c);
		free(c);
	} while (p != l);
}

int main(void)
{
	struct node *head, *p, *c;

	head = create(10);
	list(head);

	c = head->n;
	delete(c);
	list(head);

	c = create(1);
	p = head->n;
	insert(p, p->n, c);
	list(head);

	destroy(head);

	return 0;
}

