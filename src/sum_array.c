#include "../include/sum_array.h"

/*
 * Problem 1 from https://blog.svpino.com/2015/05/07/five-programming-
 * problems-every-software-engineer-should-be-able-to-solve-in-less-than-1-hour
 * Write three functions that compute the sum of the numbers in a given 
 * list using a for-loop, a while-loop, and recursion.
 */

int
sum_for_loop(int *nums, unsigned int n_nums)
{
	int sum = 0;

	for (unsigned int i = 0; i < n_nums; i++) {
		sum += nums[i];
	}

	return sum;
}

int
sum_while_loop(int *nums, unsigned int n_nums)
{
	int sum = 0;
	unsigned int i = 0;

	while (i < n_nums) {
		sum += nums[i++];
	}

	return sum;
}

int
sum_recursion(int *nums, unsigned int n_sums)
{
	
	if (n_sums == 0) {
		return 0;
	}

	if (n_sums == 1) {
		return nums[0];
	}

	return nums[0] + sum_recursion(nums + 1, n_sums - 1);
}
