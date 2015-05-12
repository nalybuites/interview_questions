#include "../../include/sort/sort_bubble.h"
#include "../../include/util.h"

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

