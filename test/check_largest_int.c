#include <stdlib.h>

#include <check.h>

#include "../include/largest_int.h"
#include "../include/util.h"

struct largest_int_test {
	unsigned int input[10];
	unsigned int n_input;
	unsigned int expected;
};

struct largest_int_test largest_int_test_data[] = {
	{ .input = {}, .n_input = 0, .expected = 0 },
	{ .input = { 9 }, .n_input = 1, .expected = 9 },
	{ .input = { 50, 2, 1, 9 }, .n_input = 4, .expected = 95021 },
	{ .input = { 50 , 50 }, .n_input = 2, .expected = 5050 },
	{ .input = { 5, 0, 5, 0 }, .n_input = 4, .expected = 5500 },
	{ .input = { 50, 51 }, .n_input = 2, .expected = 5150 },
	{ .input = { 3, 4, 5, 6, 7, 8, 9 }, .n_input = 7, .expected = 9876543 },
};

START_TEST(test_largest_int)
{
	struct largest_int_test t = largest_int_test_data[_i];

	ck_assert_int_eq(largest_int(t.input, t.n_input), t.expected);
}
END_TEST

int
main(int argc, char **argv)
{
	Suite *s;
	TCase *t_case;
	SRunner *sr;
	int n_failed;

	s = suite_create("check_largest_int");
	t_case = tcase_create("core");

	tcase_add_loop_test(t_case, test_largest_int, 0, ARRAY_SIZE(largest_int_test_data));
	
	suite_add_tcase(s, t_case);

	sr = srunner_create(s);

	srunner_run_all(sr, CK_NORMAL);
	n_failed = srunner_ntests_failed(sr);
	srunner_free(sr);

	return (n_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
