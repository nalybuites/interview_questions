#include "../include/fibonacci.h"

/* Problem 3 from https://blog.svpino.com/2015/05/07/five-programming-
 * problems-every-software-engineer-should-be-able-to-solve-in-less-than-1-hour
 *
 * Write a function that computes the list of the first 100 Fibonacci 
 * numbers. By definition, the first two numbers in the Fibonacci 
 * sequence are 0 and 1, and each subsequent number is the sum of the 
 * previous two. As an example, here are the first 10 Fibonnaci 
 * numbers: 0, 1, 1, 2, 3, 5, 8, 13, 21, and 34.
 *
 * NOTE: Fibonacci numbers where n > 93 are larger than the capacity of unsigned
 * long long, so we need something > 64 bits. Still working on that.
 */

void
fibonacci(unsigned long long *num, unsigned int n_num)
{
	
	for (unsigned int i = 0; i < n_num; i++) {
		if (i == 0) {
			num[i] = 0;
			continue;
		}

		if (i == 1) {
			num[i] = 1;
			continue;
		}

		num[i] = num[i - 1] + num[i - 2];
	}
}
