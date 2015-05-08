#include <stdlib.h>
#include <stdio.h>

struct node {
	int value;
	struct node *next;
};

struct node *
linked_list_reverse(struct node *head)
{
	struct node *new_head = NULL;
	struct node *temp = NULL;
	struct node *cursor = head;

	while (cursor != NULL) {
		temp = cursor->next;
		cursor->next = new_head;
		new_head = cursor;
		cursor = temp;
	}

	return new_head;
}

