#include "../include/sort_selection.h"

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

