#include <stdlib.h>
#include <stdio.h>

#include <check.h>

#include "../include/strip_whitespace.h"
#include "../include/util.h"

struct strip_whitespace_test {
	const char *input;
	const char *output;
};

struct strip_whitespace_test strip_whitespace_test_data[] = {
	{ .input = "foo", .output = "foo" },
	{ .input = "     foo", .output = " foo" },
	{ .input = "foo     ", .output = "foo " },
	{ .input = "foo    bar", .output = "foo bar" },
	{ .input = "foo\tbar", .output = "foo bar" },
	{ .input = "foo \t bar", .output = "foo bar" },
};

START_TEST(test_strip_whitespace)
{
	struct strip_whitespace_test t = strip_whitespace_test_data[_i];

	char *output = strip_whitespace(t.input);
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

	s = suite_create("check_strip_whitespace");
	t_case = tcase_create("core");

	tcase_add_loop_test(t_case, test_strip_whitespace, 0, ARRAY_SIZE(strip_whitespace_test_data));
	
	suite_add_tcase(s, t_case);

	sr = srunner_create(s);

	srunner_run_all(sr, CK_NORMAL);
	n_failed = srunner_ntests_failed(sr);
	srunner_free(sr);

	return (n_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
