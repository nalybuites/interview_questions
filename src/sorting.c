//#include <malloc.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/sort_bubble.h"
#include "../include/sort_heap.h"
#include "../include/sort_insertion.h"
#include "../include/sort_merge.h"
#include "../include/sort_quick.h"
#include "../include/sort_selection.h"
#include "../include/util.h"

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

static void
print_array(int input[], unsigned int n_items)
{

	for (unsigned int i = 0; i < n_items; i++) {
		printf("%d ", input[i]);
	}
}

static void
test_sort(sort_t *sort_fn, const char *description)
{
	int x[] = { 6, 5, 8, 3, 1, 2, 9, 0, 7, 4 };

	printf("%s: ", description);

	print_array(x, 10);

	printf(" => ");
	sort_fn(x, 10, int_comparator);

	print_array(x, 10);

	bool sorted = true;
	for (int i = 0; i < 10; i++) {
		if (i > 0 && x[i] < x[i - 1]) {
			sorted = false;
		}
	}

	printf(" %s\n", sorted ? "SUCCESS" : "FAILURE");
}


int
main(int argc, char **argv)
{

	test_sort(quick_sort, "quicksort");
	test_sort(merge_sort, "mergesort");
	test_sort(bubble_sort, "bubblesort");
	test_sort(selection_sort, "selectionsort");
	test_sort(insertion_sort, "insertionsort");
	test_sort(heap_sort, "heapsort");

	return 0;
}
