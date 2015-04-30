#include "../include/sort_quick.h"

/* 
 * QUICK SORT 
 */
static int
quick_sort_partition(int input[], int low, int high, compar_t *compar)
{
	int pivot = low + (high - low) / 2;
	int pivot_value = input[pivot];
	int swap;
	int temp_index;
	
	/* Swap values */
	swap = input[high];
	input[high] = input[pivot];
	input[pivot] = swap;

	temp_index = low;

	for (int i = low; i < high; i++) {
		if (compar(&input[i], &pivot_value) >= 0) {
			swap = input[i];
			input[i] = input[temp_index];
			input[temp_index] = swap;

			temp_index++;
		}
	}

	swap = input[temp_index];
	input[temp_index] = input[high];
	input[high] = swap;

	return temp_index;
}

static void
quick_sort_internal(int input[], int low, int high, compar_t *compar)
{
	int partition;
	
	if (low >= high) {
		return;
	}

	partition = quick_sort_partition(input, low, high, compar);
	quick_sort_internal(input, low, partition - 1, compar);
	quick_sort_internal(input, partition + 1, high, compar);
}

void
quick_sort(int input[], unsigned int n_items, compar_t *compar)
{

	quick_sort_internal(input, 0, n_items - 1, compar);
}

