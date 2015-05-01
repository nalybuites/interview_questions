#include <stdlib.h>
#include <stdio.h>

#include <check.h>

#include "../include/itoa.h"
#include "../include/util.h"

struct itoa_test {
	int input;
	unsigned int base;
	const char *output;
};

struct itoa_test itoa_test_data[] = {
	{ .input = 123, .base = 2, .output = "0b1111011" },
	{ .input = 123, .base = 8, .output = "0173" },
	{ .input = 123, .base = 10, .output = "123" },
	{ .input = 123, .base = 16, .output = "0x7b" },
	{ .input = -123, .base = 2, .output = "-0b1111011" },
	{ .input = -123, .base = 8, .output = "-0173" },
	{ .input = -123, .base = 10, .output = "-123" },
	{ .input = -123, .base = 16, .output = "-0x7b" },
};

START_TEST(test_itoa)
{
	struct itoa_test t = itoa_test_data[_i];
	char *output = int_itoa(t.input, t.base);

	ck_assert(strcmp(output, t.output) == 0);
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

	tcase_add_loop_test(t_case, test_itoa, 0, ARRAY_SIZE(itoa_test_data));
	
	suite_add_tcase(s, t_case);

	sr = srunner_create(s);

	srunner_run_all(sr, CK_NORMAL);
	n_failed = srunner_ntests_failed(sr);
	srunner_free(sr);

	return (n_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
