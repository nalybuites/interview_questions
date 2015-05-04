#include <stdlib.h>

int *
int_set_intersect(unsigned int *n_out, int *one, unsigned int n_one, int *two, unsigned int n_two)
{
	int *out = calloc(n_one + n_two, sizeof(int));
	unsigned int one_i = 0;
	unsigned int two_i = 0;
	unsigned int out_i = 0;

	while (one[one_i] <= two[two_i] && one_i < n_one && two_i < n_two) {
		if (one[one_i] < two[two_i]) {
			one_i++;
			continue;
		}

		if (one[one_i] == two[two_i]) {
			out[out_i++] = one[one_i];
			one_i++;
			two_i++;
			continue;
		}
	}

	out = realloc(out, out_i);
	*n_out = out_i;

	return out;
}

