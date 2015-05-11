#include <stdlib.h>

#include <check.h>

#include "../include/sum_array.h"
#include "../include/util.h"

struct sum_array_test {
	int nums[10];
	unsigned int n_nums;
	int sum;
};

struct sum_array_test sum_array_test_data[] = {
	{ .nums = {}, .n_nums = 0, .sum = 0 },
	{ .nums = { 0 }, .n_nums = 1, .sum = 0 },
	{ .nums = { 0, 1 }, .n_nums = 2, .sum = 1 },
	{ .nums = { 0, 1, 2 }, .n_nums = 3, .sum = 3 },
	{ .nums = { 0, 1, 2, 3 }, .n_nums = 4, .sum = 6 },
	{ .nums = { 0, 1, 2, 3, 4 }, .n_nums = 5, .sum = 10 },
	{ .nums = { 0, 1, 2, 3, 4, 5 }, .n_nums = 6, .sum = 15 },
	{ .nums = { 0, 1, 2, 3, 4, 5, 6 }, .n_nums = 7, .sum = 21 },
	{ .nums = { 0, 1, 2, 3, 4, 5, 6, 7 }, .n_nums = 8, .sum = 28 },
	{ .nums = { 0, 1, 2, 3, 4, 5, 6, 7, 8 }, .n_nums = 9, .sum = 36 },
	{ .nums = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 }, .n_nums = 10, .sum = 45 },
};

START_TEST(test_sum_for_loop)
{
	struct sum_array_test t = sum_array_test_data[_i];

	ck_assert_int_eq(t.sum, sum_for_loop(t.nums, t.n_nums));
}
END_TEST

START_TEST(test_sum_while_loop)
{
	struct sum_array_test t = sum_array_test_data[_i];

	ck_assert_int_eq(t.sum, sum_while_loop(t.nums, t.n_nums));
}
END_TEST

START_TEST(test_sum_recursion)
{
	struct sum_array_test t = sum_array_test_data[_i];

	ck_assert_int_eq(t.sum, sum_recursion(t.nums, t.n_nums));
}
END_TEST

int
main(int argc, char **argv)
{
	Suite *s;
	TCase *t_case;
	SRunner *sr;
	int n_failed;

	s = suite_create("check_sum_array");
	t_case = tcase_create("core");

	tcase_add_loop_test(t_case, test_sum_for_loop, 0, ARRAY_SIZE(sum_array_test_data));
	tcase_add_loop_test(t_case, test_sum_while_loop, 0, ARRAY_SIZE(sum_array_test_data));
	tcase_add_loop_test(t_case, test_sum_recursion, 0, ARRAY_SIZE(sum_array_test_data));
	
	suite_add_tcase(s, t_case);

	sr = srunner_create(s);

	srunner_run_all(sr, CK_NORMAL);
	n_failed = srunner_ntests_failed(sr);
	srunner_free(sr);

	return (n_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
