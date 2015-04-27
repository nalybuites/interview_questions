#include <stdio.h>

typedef int compar_t(const void *, const void *);

int
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

void
merge_sort(int input[], unsigned int n_items, compar_t *compar)
{

}

void
bubble_sort(int input[], unsigned int n_items, compar_t *compar)
{

}

void
insertion_sort(int input[], unsigned int n_items, compar_t *compar)
{

}

void
selection_sort(int input[], unsigned int n_items, compar_t *compar)
{

}

void
heapsort(int input[], unsigned int n_items, compar_t *compar)
{

}

int
main(int argc, char **argv)
{
	int x[] = { 6, 5, 8, 3, 1, 2, 9, 0, 7, 4 };

	for (int i = 0; i < 10; i++) {
		printf("%d", x[i]);
	}
	printf(" => ");
	quick_sort(x, 10, int_comparator);
	for (int i = 0; i < 10; i++) {
		printf("%d", x[i]);
	}
	printf("\n");

	return 0;
}
