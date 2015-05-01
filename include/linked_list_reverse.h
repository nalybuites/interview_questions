#ifndef _LINKED_LIST_REVERSE_H_
#define _LINKED_LIST_REVERSE_H_

struct node {
	int value;
	struct node *next;
};

struct node *linked_list_reverse(struct node *head);

#endif /* _LINKED_LIST_REVERSE_H_ */
