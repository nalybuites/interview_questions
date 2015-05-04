#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include <check.h>

#include "../include/int_set_intersect.h"
#include "../include/util.h"

struct int_set_intersect_test {
	int one[10];
	unsigned int n_one;
	int two[10];
	unsigned int n_two;
	int result[10];
	unsigned int n_result;
};

struct int_set_intersect_test int_set_intersect_test_data[] = {
	{ .one = { 1 }, .n_one = 1, .two = { 2 }, .n_two = 1, .result = { }, .n_result = 0 },
	{ .one = { 1 }, .n_one = 1, .two = { 1 }, .n_two = 1, .result = { 1 }, .n_result = 1 },
	{ .one = { 1, 2, 3, 4}, .n_one = 4, .two = { 1, 4, 5 }, .n_two = 3, .result = { 1, 4 }, .n_result = 2 },
	{ .one = { 6, 7, 8, 9}, .n_one = 4, .two = { 1, 2, 3, 4 }, .n_two = 4, .result = { }, .n_result = 0 },
};

static bool
is_set_correct(int *correct, unsigned int n_correct, int *test, unsigned int n_test)
{

	if (n_correct != n_test) {
		return false;
	}

	for (unsigned int i = 0; i < n_correct; i++) {
		if (correct[i] != test[i]) {
			return false;
		}
	}

	return true;
}

START_TEST(test_int_set_intersect)
{
	struct int_set_intersect_test t = int_set_intersect_test_data[_i];
	unsigned int n_out = 0;
	int *output = int_set_intersect(&n_out, t.one, t.n_one, t.two, t.n_two);

	ck_assert(is_set_correct(t.result, t.n_result, output, n_out));
	free(output);
}
END_TEST

int
main(int argc, char **argv)
{
	Suite *s;
	TCase *t_case;
	SRunner *sr;
	int n_failed;

	s = suite_create("check_itoa");
	t_case = tcase_create("core");

	tcase_add_loop_test(t_case, test_int_set_intersect, 0, ARRAY_SIZE(int_set_intersect_test_data));
	
	suite_add_tcase(s, t_case);

	sr = srunner_create(s);

	srunner_run_all(sr, CK_NORMAL);
	n_failed = srunner_ntests_failed(sr);
	srunner_free(sr);

	return (n_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
