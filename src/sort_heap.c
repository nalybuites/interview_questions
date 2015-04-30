#include <math.h>

#include "../include/sort_heap.h"

/*
 * HEAP SORT
 */
static void
heap_sort_sift_down(int input[], unsigned int start_i, unsigned int end_i, compar_t *compar)
{
	unsigned int root_i = start_i;

	while ((root_i * 2 + 1) <= end_i) {
		unsigned int child_i = root_i * 2 + 1;
		unsigned int swap_i = root_i;

		if (compar(&input[swap_i], &input[child_i]) > 0) {
			swap_i = child_i;
		}

		if (child_i + 1 <= end_i && compar(&input[swap_i], &input[child_i + 1]) > 0) {
			swap_i = child_i + 1;
		}

		if (swap_i == root_i) {
			return;
		}

		int temp = input[root_i];
		input[root_i] = input[swap_i];
		input[swap_i] = temp;

		root_i = swap_i;
	}
}

static void
heap_sort_heapify(int input[], unsigned int n_items, compar_t *compar)
{
	int start_i = floor((n_items  - 2.0) / 2.0);

	while (start_i >= 0) {
		heap_sort_sift_down(input, start_i, n_items - 1, compar);
		start_i--;
	}
}

void
heap_sort(int input[], unsigned int n_items, compar_t *compar)
{
	unsigned int end_i = n_items - 1;

	heap_sort_heapify(input, n_items, compar);

	while (end_i > 0) {
		int temp = input[0];
		input[0] = input[end_i];
		input[end_i] = temp;

		end_i--;

		heap_sort_sift_down(input, 0, end_i, compar);
	}
}

