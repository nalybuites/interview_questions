#include <stdio.h>
#include <stdlib.h>

static int
binary_search_int(int haystack[], int needle, int low, int high)
{
	int med = (high + low) / 2;

	if (needle == haystack[med]) {
		return med;
	}

	if (needle > haystack[med] && needle <= haystack[high]) {
		return binary_search_int(haystack, needle, med, high);
	}

	if (needle < haystack[med] && needle >= haystack[low]) {
		return binary_search_int(haystack, needle, low, med);
	}

	return -1;
}

int
binary_search(int haystack[], int needle, unsigned int n_haystack)
{

	return binary_search_int(haystack, needle, 0, n_haystack - 1);
}

int
main(int argc, char **argv)
{
	int x[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int needle;
	int index = -1;

	if (argc < 2) {
		printf("missing args\n");
		return 1;
	}

	needle = atoi(argv[1]);
	index = binary_search(x, needle, 10);

	printf("binary_search: %d => %d\n", needle, index);

	return 0;
}
