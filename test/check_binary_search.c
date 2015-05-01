#include <stdlib.h>

#include <check.h>

#include "../include/binary_search.h"
#include "../include/util.h"

int haystack[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

struct binary_search_test {
	int needle;
	unsigned int index;
};

struct binary_search_test binary_search_test_data[] = {
	{ .needle = -1, .index = -1 },
	{ .needle = 0, .index = 0 },
	{ .needle = 1, .index = 1 },
	{ .needle = 2, .index = 2 },
	{ .needle = 3, .index = 3 },
	{ .needle = 4, .index = 4 },
	{ .needle = 5, .index = 5 },
	{ .needle = 6, .index = 6 },
	{ .needle = 7, .index = 7 },
	{ .needle = 8, .index = 8 },
	{ .needle = 9, .index = 9 },
	{ .needle = 10, .index = -1 },
};

START_TEST(test_binary_search)
{
	struct binary_search_test t = binary_search_test_data[_i];

	ck_assert_int_eq(binary_search(haystack, t.needle, ARRAY_SIZE(haystack)), t.index);
}
END_TEST

int
main(int argc, char **argv)
{
	Suite *s;
	TCase *t_case;
	SRunner *sr;
	int n_failed;

	s = suite_create("check_binary_search");
	t_case = tcase_create("core");

	tcase_add_loop_test(t_case, test_binary_search, 0, ARRAY_SIZE(binary_search_test_data));
	
	suite_add_tcase(s, t_case);

	sr = srunner_create(s);

	srunner_run_all(sr, CK_NORMAL);
	n_failed = srunner_ntests_failed(sr);
	srunner_free(sr);

	return (n_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
