#include <malloc.h>
#include <string.h>

#include "../include/sort_merge.h"

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
		if (temp_left < middle_i && (temp_right >= end_i || compar(&input[temp_left], &input[temp_right]) >= 0)) {
			temp[j] = input[temp_left++];
		} else {
			temp[j] = input[temp_right++];
		}
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

