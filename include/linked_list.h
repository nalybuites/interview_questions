#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_

#include <stdbool.h>

struct node {
	int value;
	struct node *next;
};

bool linked_list_has_cycle(struct node *head);
struct node *linked_list_find_middle(struct node *head);
void linked_list_split(struct node *head, int pivot, struct node **lt, struct node **gt);
void linked_list_insert(struct node **head, int value);
void linked_list_delete(struct node **head, int value);
void linked_list_reverse(struct node **head);

#endif /* _LINKED_LIST_H_ */

