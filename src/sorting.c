#include <malloc.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

typedef int compar_t(const void *, const void *);
typedef void sort_t(int [], unsigned int, compar_t *);

#define max(a,b) \
	({ __typeof__ (a) _a = (a); \
		__typeof__ (b) _b = (b); \
		_a > _b ? _a : _b; })

#define min(a,b) \
	({ __typeof__ (a) _a = (a); \
		__typeof__ (b) _b = (b); \
		_a < _b ? _a : _b; })

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

static void
merge_sort_merge(int input[], int temp[], unsigned int begin_i, unsigned int middle_i, unsigned int end_i,
    compar_t *compar)
{
	unsigned int temp_left = begin_i;
	unsigned int temp_right = middle_i;

	printf("\n");

	for (unsigned int j = begin_i; j < end_i; j++) {
		if (temp_left < temp_right ||
		    (temp_right >= end_i || compar(&input[temp_left], &input[temp_right]) >= 0)) {
			temp[j] = input[temp_left++];
		} else {
			temp[j] = input[temp_right++];
		}
		printf("placed %d at %u in [%u, %u, %u)\n", temp[j], j, begin_i, middle_i, end_i); 
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

	memcpy(input, temp, (end_i - begin_i) * sizeof(int));

	printf("\n");
	print_array(input + begin_i, (end_i - begin_i));
	printf("\n");
}
void
merge_sort(int input[], unsigned int n_items, compar_t *compar)
{
	int *temp = calloc(n_items, sizeof(int));

	merge_sort_internal(input, temp, 0, n_items - 1, compar);

	free(temp);
}

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

void
heap_sort(int input[], unsigned int n_items, compar_t *compar)
{

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
//	test_sort(merge_sort, "mergesort");
	test_sort(bubble_sort, "bubblesort");
	test_sort(selection_sort, "selectionsort");
	test_sort(insertion_sort, "insertionsort");
	test_sort(heap_sort, "heapsort");

	return 0;
}
