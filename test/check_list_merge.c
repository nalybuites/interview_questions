#include <stdlib.h>
#include <stdbool.h>

#include <check.h>

#include "../include/list_merge.h"
#include "../include/util.h"

struct list_merge_test {
	int left[10];
	unsigned int n_left;
	int right[10];
	unsigned int n_right;
	int result[20];
	unsigned int n_result;
};

struct list_merge_test list_merge_test_data[] = {
	{ .left = { 0, 2, 4 }, .n_left = 3, .right = { 1, 3, 5 }, .n_right = 3, .result = { 0, 1, 2, 3, 4, 5 }, .n_result = 6 },
	{ .left = { 0, 2, 4 }, .n_left = 3, .right = { 1, 3, 5, 7 }, .n_right = 4, .result = {}, .n_result = 0 },
	{ .left = {}, .n_left = 0, .right = {}, .n_right = 0, .result = {}, .n_result = 0 },
};

static bool
check_lists(int *result, unsigned int n_result, int *expected, unsigned int n_expected)
{
	
	if (n_result != n_expected) {
		return false;
	}

	for (unsigned int i = 0; i < n_result; i++) {
		if (result[i] != expected[i]) {
			return false;
		}
	}

	return true;
}

START_TEST(test_list_merge)
{
	struct list_merge_test t = list_merge_test_data[_i];
	int *result = calloc(t.n_left + t.n_right, sizeof(int));
	unsigned int n_result = 0;

	list_merge(result, &n_result, t.left, t.n_left, t.right, t.n_right);
	
	ck_assert(check_lists(result, n_result, t.result, t.n_result));
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

	tcase_add_loop_test(t_case, test_list_merge, 0, ARRAY_SIZE(list_merge_test_data));
	
	suite_add_tcase(s, t_case);

	sr = srunner_create(s);

	srunner_run_all(sr, CK_NORMAL);
	n_failed = srunner_ntests_failed(sr);
	srunner_free(sr);

	return (n_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
