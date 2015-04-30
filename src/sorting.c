#include <malloc.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#include "util.h"

typedef int compar_t(const void *, const void *);
typedef void sort_t(int [], unsigned int, compar_t *);

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

/* 
 * QUICK SORT 
 */
static void
print_array(int input[], unsigned int n_items)
{

	for (unsigned int i = 0; i < n_items; i++) {
		printf("%d ", input[i]);
	}
}

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

/*
 * MERGE SORT
 */
static void
merge_sort_merge(int input[], int temp[], unsigned int begin_i, unsigned int middle_i, unsigned int end_i,
    compar_t *compar)
{
	unsigned int temp_left = begin_i;
	unsigned int temp_right = middle_i;

	for (unsigned int j = begin_i; j < end_i; j++) {
		if (temp_left < middle_i && (temp_right >= end_i || input[temp_left] <= input[temp_right])) {
			temp[j] = input[temp_left++];
		} else {
			temp[j] = input[temp_right++];
		}
	}
}

void
copy_array(int input[], int temp[], unsigned int begin_i, unsigned int end_i)
{

		for (unsigned int k = begin_i; k < end_i; k++) {
			input[k] = temp[k];
		}
}

static void
merge_sort_internal(int input[], int temp[], unsigned int begin_i, unsigned int end_i, compar_t *compar)
{
	unsigned int middle_i;

	if (end_i - begin_i < 2) {
		return;
	}

	middle_i = (begin_i + end_i) / 2;
	merge_sort_internal(input, temp, begin_i, middle_i, compar);
	merge_sort_internal(input, temp, middle_i, end_i, compar);
	merge_sort_merge(input, temp, begin_i, middle_i, end_i, compar);

	memcpy(input + begin_i, temp + begin_i, (end_i - begin_i) * sizeof(int));
}

void
merge_sort(int input[], unsigned int n_items, compar_t *compar)
{
	int *temp = calloc(n_items, sizeof(int));

	merge_sort_internal(input, temp, 0, n_items, compar);

	free(temp);
}

/*
 * BUBBLE SORT
 */
void
bubble_sort(int input[], unsigned int n_items, compar_t *compar)
{
	unsigned int n_swaps = 0;

	do {
		n_swaps = 0;

		for (unsigned int j = 1; j < n_items; j++) {
			if (input[j - 1] > input[j]) {
				int temp = input[j - 1];
				input[j - 1] = input[j];
				input[j] = temp;
				n_swaps++;
			}
		}
	} while (n_swaps > 0);
}

/*
 * INSERTION SORT
 */
void
insertion_sort(int input[], unsigned int n_items, compar_t *compar)
{

	for (unsigned int i = 1; i < n_items; i++) {
		int temp = input[i];
		unsigned int j = i;

		while (j > 0 && compar(&temp, &input[j - 1]) > 0) {
			input[j] = input[j - 1];
			j--;
		}

		input[j] = temp;
	}
}

/*
 * SELECTION SORT
 */
void
selection_sort(int input[], unsigned int n_items, compar_t *compar)
{
	unsigned int current_min;

	for (unsigned int i = 0; i < n_items; i++) {
		unsigned int j;
		current_min = i;

		for (j = i; j < n_items; j++) {
			if (compar(&input[j], &input[current_min]) > 0) {
				current_min = j;
			}
		}
	
		if (current_min > i) {
			int temp = input[i];
			input[i] = input[current_min];
			input[current_min] = temp;
		}
	}
}

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
