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

		if (left >= right) {
			break;
		}

		temp = *left;
		*left = *right;
		*right = temp;

		left++;
		right--;
	}
}

