#include <malloc.h>
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

int
main(int argc, char **argv)
{
	int x[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	struct node *head = NULL;
	struct node *cursor;
	struct node *temp;

	for (int i = 9; i >= 0; i--) {
		cursor = calloc(1, sizeof(struct node));
		cursor->value = x[i];
		cursor->next = head;

		head = cursor;
	}

	temp = head;
	while (head != NULL) {
		cursor = head;
		printf("%d%s", cursor->value, (cursor->next == NULL) ? "" : " -> ");
		
		head = cursor->next;
	}

	head = linked_list_reverse(temp);
	printf(" => ");

	while (head != NULL) {
		cursor = head;
		printf("%d%s", cursor->value, (cursor->next == NULL) ? "" : " -> ");
		
		head = cursor->next;

		free(cursor);
	}

	printf("\n");

	return 0;
}
