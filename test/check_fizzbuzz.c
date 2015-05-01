#include <stdlib.h>

#include <check.h>

#include "../include/fizzbuzz.h"

START_TEST(test_fizzbuzz)
{
	const char *result = fizzbuzz(_i);

	if (_i % 3 == 0 && _i % 5 == 0) {
		ck_assert(strcmp(result, "FizzBuzz") == 0);
	} else if (_i % 3 == 0) {
		ck_assert(strcmp(result, "Fizz") == 0);
	} else if (_i % 5 == 0) {
		ck_assert(strcmp(result, "Buzz") == 0);
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

	s = suite_create("check_fizzbuzz");
	t_case = tcase_create("core");

	tcase_add_loop_test(t_case, test_fizzbuzz, 0, 100);
	
	suite_add_tcase(s, t_case);

	sr = srunner_create(s);

	srunner_run_all(sr, CK_NORMAL);
	n_failed = srunner_ntests_failed(sr);
	srunner_free(sr);

	return (n_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
