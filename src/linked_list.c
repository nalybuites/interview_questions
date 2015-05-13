#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "../include/linked_list.h"

bool
linked_list_has_cycle(struct node *head)
{
	struct node *orig_head;

	if (head == NULL) {
		return false;
	}

	orig_head = head;

	while(head != NULL) {
		if (head == orig_head) {
			return true;
		}

		head = head->next;
	}

	return false;
}

struct node *
linked_list_find_middle(struct node *head)
{
	struct node *middle;
	unsigned int i = 0;

	if (head == NULL) {
		return NULL;
	}

	middle = head;

	while (head != NULL) {
		if (i % 2 == 1) {
			middle = middle->next;
		}

		head = head->next;
		i++;
	}

	return middle;
}

void
linked_list_split(struct node *head, int pivot, struct node **lt, struct node **gt)
{
	struct node *less = NULL;
	struct node *greater = NULL;
	struct node *x = NULL;

	while (head != NULL) {
		struct node *dest;

		if (head->value == pivot) {
			/* do nothing and move on */
			head = head->next;
		}


		if (head->value > pivot) {
			dest = greater;
		} else {
			dest = less;
		}

		linked_list_insert(&dest, head->value);
	}

	*lt = less;
	*gt = greater;

	return;
}

void
linked_list_insert(struct node **head, int value)
{

	if (head == NULL) {
		return;
	}

	struct node *x = calloc(1, sizeof(struct node));
	x->value = value;
	if (*head != NULL) {
		x->next = *head;
	}
	
	*head = x;

	return;
}

static void
linked_list_delete_single(struct node** x, struct node *previous)
{
	struct node *to_delete = NULL;
	
	if (x == NULL) {
		return;
	}

	if (*x == NULL) {
		return;
	}

	to_delete = *x;

	if (previous != NULL) {
		previous->next = to_delete->next;
	}

	*x = previous->next;

	free(to_delete);

	return;
}

void
linked_list_delete(struct node **head, int value)
{
	struct node *cursor;
	struct node *previous;

	if (head == NULL) {
		return;
	}

	if (*head == NULL) {
		return;
	}

	cursor = *head;
	previous = NULL;

	while(cursor != NULL) {
		if (cursor->value == value) {
			linked_list_delete_single(&cursor, previous);

			continue;
		}

		previous = cursor;
		cursor = cursor->next;
	}

	return;
}

void
linked_list_reverse(struct node **head)
{
	struct node *new_head = NULL;
	struct node *temp = NULL;
	struct node *cursor = *head;

	while (cursor != NULL) {
		temp = cursor->next;
		cursor->next = new_head;
		new_head = cursor;
		cursor = temp;
	}

	*head = new_head;

	return;
}

