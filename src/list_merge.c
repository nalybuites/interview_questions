
#include "../include/list_merge.h"

void
list_merge(int *list, unsigned int *n_list, int *left, unsigned int n_left, int *right, unsigned int n_right)
{

	*n_list = 0;
	
	if (n_left != n_right) {
		return;
	}

	for (unsigned int i = 0; i < n_left; i++) {
		list[(*n_list)++] = left[i];
		list[(*n_list)++] = right[i];
	}
}
