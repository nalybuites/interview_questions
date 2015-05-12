#include <stdbool.h>
#include <stdlib.h>

#include <check.h>

#include "../include/sort/sort_bubble.h"
#include "../include/sort/sort_heap.h"
#include "../include/sort/sort_insertion.h"
#include "../include/sort/sort_merge.h"
#include "../include/sort/sort_quick.h"
#include "../include/sort/sort_selection.h"
#include "../include/util.h"

#define MAX_SORTING_TESTS 20

static int
int_comparator(const void *a, const void *b)
{
	int one = *(const int *)a;
	int two = *(const int *)b;

	if (one == two) {
		return 0;
	}

	if (one > two) {
		return -1;
	}

	return 1;
}

static int *
build_array(unsigned int n_items, unsigned int max_val)
{
	int *x = calloc(n_items, sizeof(int));

	for (unsigned int i = 0; i < n_items; i++) {
		x[i] = rand() * max_val;
	}

	return x;
}

static bool
is_sorted(int x[], unsigned int n_items)
{

	for (unsigned int i = 1; i < n_items; i++) {
		if (x[i] < x[i - 1]) {
			return false;
		}
	}

	return true;
}

sort_t *sort_fns[] = {
	bubble_sort,
	heap_sort,
	insertion_sort,
	merge_sort,
	quick_sort,
	selection_sort,
};

START_TEST(test_sorting)
{
	sort_t *t = sort_fns[_i];

	for (unsigned int i = 0; i < MAX_SORTING_TESTS; i++) {
		int *x = build_array(i, 2 * i);
		t(x, i, int_comparator);
		ck_assert(is_sorted(x, i));
		free(x);
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

	s = suite_create("check_sorting");
	t_case = tcase_create("core");

	tcase_add_loop_test(t_case, test_sorting, 0, ARRAY_SIZE(sort_fns));
	
	suite_add_tcase(s, t_case);

	sr = srunner_create(s);

	srunner_run_all(sr, CK_NORMAL);
	n_failed = srunner_ntests_failed(sr);
	srunner_free(sr);

	return (n_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
