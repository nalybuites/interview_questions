#include <stdlib.h>

#include <check.h>

#include "../include/linked_list.h"
#include "../include/linked_list_reverse.h"
#include "../include/util.h"

START_TEST(test_linked_list_reverse)
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

	head = linked_list_reverse(head);

	unsigned int val = 9;
	cursor = head;
	while(cursor != NULL) {
		ck_assert_int_eq(cursor->value, val--);
		temp = cursor;
		cursor = cursor->next;
		free(temp);
	}
}
END_TEST

int
main(int argc, char **argv)
{
	Suite *s;
	TCase *t_case;
	SRunner *sr;
	int n_failed;

	s = suite_create("check_atoi");
	t_case = tcase_create("core");

	tcase_add_test(t_case, test_linked_list_reverse);
	
	suite_add_tcase(s, t_case);

	sr = srunner_create(s);

	srunner_run_all(sr, CK_NORMAL);
	n_failed = srunner_ntests_failed(sr);
	srunner_free(sr);

	return (n_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
