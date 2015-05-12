#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "../include/largest_int.h"

/* 
 * Problem 4 from https://blog.svpino.com/2015/05/07/five-programming-
 * problems-every-software-engineer-should-be-able-to-solve-in-less-than-1-hour
 *
 * Write a function that given a list of non negative integers, arranges them 
 * such that they form the largest possible number. For example, given 
 * [50, 2, 1, 9], the largest formed number is 95021.
 */

/*
 * 
 * The trick in the approach is to favor the longer or lexicographically last string.
 * For example, with "9" vs "50" we should favor "9" over "50". However, with "5" vs "50",
 * we should favor "50"
 */
static int
compar(const void *one, const void *two)
{
	const char *a = (const char *)one;
	const char *b = (const char *)two;

	while(*a != '\0' && *b != '\0') {
		/* a and b are the same, move onto next char */
		if (*a == *b) {
			a++;
			b++;
			continue;
		}

		/* b is shorter than or lexicographically before a */
		if (*a == '\0' || *b < *a) {
			return -1;
		}

		/* a is shorter than or lexicographically before b */
		if (*b == '\0' || *a < *b) {
			return 1;
		}
	}

	/* strings are identical */
	return 0;
}

unsigned int
largest_int(unsigned int *nums, unsigned int n_nums)
{
	char **strs = calloc(n_nums, sizeof(char *));
	size_t max_len = 0;
	char *result = NULL;
	unsigned int largest = 0;

	for (unsigned int i = 0; i < n_nums; i++) {
		char buf[33];
		memset(buf, 0, sizeof(buf));
		max_len += sprintf(buf, "%d", nums[i]);
		strs[i] = strdup(buf);
	}

	qsort(strs, n_nums, sizeof(char *), compar); 
	result = calloc(max_len, sizeof(char));

	for (unsigned int i = 0; i < n_nums; i++) {
		strcat(result, strs[i]);
		free(strs[i]);
	}
	free(strs);

	largest = atoi(result);

	free(result);

	return largest;
}
