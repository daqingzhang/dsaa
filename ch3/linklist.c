#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *previous;
	struct node *next;
};

void init(struct node *l)
{
	l->data = 0;
	l->previous = l;
	l->next = l;
}

void show(struct node *n)
{
	printf("node[%p]: data = %x, previous = %p, next = %p\n",
		n, n->data, n->previous, n->next);
}

struct node *insert(struct node *p, struct node *n, struct node *node)
{
	node->previous = p;
	node->next = n;
	p->next = node;
	n->previous = node;

	return p;
}

struct node *create(int cnt)
{
	int i;
	struct node *head, *p, *n;

	head = (struct node *)malloc(cnt * sizeof(struct node));
	if (!head) {
		printf("malloc failed\n");
		return NULL;
	}
	init(head);
//	head->data = cnt;

	p = head;
	n = head;

	for(i = 0;i < cnt; i++) {
		insert(p, p, n);
		p = n;
		n = n + 1;
	}

	n = head;
	for(i = 0;i < cnt; i++)
		show(n++);

	return head;
}

void destroy(struct node *l)
{
	struct node *n = l;

	while(l != NULL) {
		l = l->next;
		n->next = NULL;
		printf("to free node %p\n", n);
		free(n);
		n = l;
	}
}


int main(void)
{
	struct node *head;

	head = create(10);
	head->data = 10;

	show(head);
	destroy(head);

	return 0;
}

