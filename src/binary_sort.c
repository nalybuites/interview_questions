#include <stdio.h>
#include <string.h>

int
main (int argc, char **argv)
{

	if (argc != 2 || argv[1] == NULL) {
		printf("Missing args\n");
		return 1;
	}

	char *digits = strdup(argv[1]);
	unsigned int n_digits = strlen(digits);

	if (n_digits == 0) {
		printf("Empty array\n");
		return 1;
	}

	char *left = digits;
	char *right = digits + n_digits;

	while (left <= right) {
		while (*left != '0') {
			left++;
		}

		while (*right != '1') {
			right--;
		}

		char temp = *left;
		*left = *right;
		*right = temp;

		left++;
		right--;
	}

	printf("binary_sort: %s => %s\n", argv[1], digits);

	free(digits);

	return 0;
}
