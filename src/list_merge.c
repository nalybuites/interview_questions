#include "../include/list_merge.h"

/*
 * Problem 2 from https://blog.svpino.com/2015/05/07/five-programming-
 * problems-every-software-engineer-should-be-able-to-solve-in-less-than-1-hour
 *
 * Write a function that combines two lists by alternatingly taking elements. 
 * For example: given the two lists [a, b, c] and [1, 2, 3], the function 
 * should return [a, 1, b, 2, c, 3].
 */

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
