#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include <check.h>

#include "../include/binary_sort.h"
#include "../include/util.h"

char *binary_sort_test_data[] = {
	"10101010101010",
	"11111111000000",
	"00000000111111",
	"01010101010101",
	"1111000011110000",
	"0000111100001111",
};

bool
check_result(const char *result)
{
	unsigned int n_chars = strlen(result);
	bool check_for_ones = false;

	for (unsigned int i = 0; i < n_chars; i++) {
		if (check_for_ones && result[i] == '1') {
			return false;
		}

		if (result[i] == '0') {
			check_for_ones = true;
		}
	}

	return true;
}

START_TEST(test_binary_sort)
{
	char *t = strdup(binary_sort_test_data[_i]);

	binary_sort(t);
	ck_assert(check_result(t));
	free(t);
}
END_TEST

int
main (int argc, char **argv)
{
	Suite *s;
	TCase *t_case;
	SRunner *sr;
	int n_failed;

	s = suite_create("check_binary_sort");
	t_case = tcase_create("core");
	tcase_set_timeout(t_case, 100000);
	tcase_add_loop_test(t_case, test_binary_sort, 0, ARRAY_SIZE(binary_sort_test_data));
	
	suite_add_tcase(s, t_case);

	sr = srunner_create(s);

	srunner_run_all(sr, CK_NORMAL);
	n_failed = srunner_ntests_failed(sr);
	srunner_free(sr);

	return (n_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
