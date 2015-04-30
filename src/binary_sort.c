#include <malloc.h>
#include <stdio.h>
#include <string.h>

void
binary_sort(char *digits)
{
	unsigned int n_digits;
	char *left;
	char *right;
	
	if (digits == NULL) {
		return;
	}

	n_digits = strlen(digits);

	if (n_digits == 0) {
		return;
	}

	left = digits;
	right = digits + n_digits;

	while (left <= right) {
		char temp;

		while (*left != '0') {
			left++;
		}

		while (*right != '1') {
			right--;
		}

		temp = *left;
		*left = *right;
		*right = temp;

		left++;
		right--;
	}
}

int
main (int argc, char **argv)
{

	if (argc != 2 || argv[1] == NULL) {
		printf("Missing args\n");
		return 1;
	}

	char *digits = strdup(argv[1]);
	binary_sort(digits);

	printf("binary_sort: %s => %s\n", argv[1], digits);

	free(digits);

	return 0;
}
