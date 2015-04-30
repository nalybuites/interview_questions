#include "../include/sort_insertion.h"

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

