#include <stdlib.h>

#include <check.h>

#include "../include/atoi.h"
#include "../include/util.h"

struct atoi_test {
	const char *input;
	int expected;
};

struct atoi_test atoi_test_data[] = {
	{ .input = "1234567890", .expected = 1234567890 },
	{ .input = "987654321", .expected = 987654321 },
	{ .input = "-123", .expected = -123 },
	{ .input = "123", .expected = 123 },
	{ .input = "123.456", .expected = 123 },
	{ .input = "-123.4567", .expected = -123 },
	{ .input = "0", .expected = 0 },
};

START_TEST(test_atoi)
{
	struct atoi_test t = atoi_test_data[_i];

	ck_assert_int_eq(int_atoi(t.input), t.expected);
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

	tcase_add_loop_test(t_case, test_atoi, 0, ARRAY_SIZE(atoi_test_data));
	
	suite_add_tcase(s, t_case);

	sr = srunner_create(s);

	srunner_run_all(sr, CK_NORMAL);
	n_failed = srunner_ntests_failed(sr);
	srunner_free(sr);

	return (n_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
