#include <stdio.h>
#include <stdlib.h>

#include "../include/binary_search.h"

static int
binary_search_int(int haystack[], int needle, int low, int high)
{
	int med = (high + low) / 2;

	if (needle == haystack[med]) {
		return med;
	}

	if (needle >= haystack[low] && needle < haystack[med]) {
		return binary_search_int(haystack, needle, low, med - 1);
	}

	if (needle > haystack[med] && needle <= haystack[high]) {
		return binary_search_int(haystack, needle, med + 1, high);
	}

	return -1;
}

int
binary_search(int haystack[], int needle, unsigned int n_haystack)
{

	return binary_search_int(haystack, needle, 0, n_haystack - 1);
}

