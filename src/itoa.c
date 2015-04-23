#include <math.h>
#include <stdio.h>
#include <stdlib.h>

/*
 * Traditional itoa() implementation
 */

int
main(int argc, char **argv)
{
	if (argc < 3) {
		printf("Missing args\n");
		return 1;
	}

	int input_num = (argv[0] == NULL) ? 0 : strtol(argv[1], NULL, 10);
	int num = input_num;
	int output_base = (argv[1] == NULL) ? 10 : strtol(argv[2], NULL, 10);
	char *reference_chars = "0123456789abcdef";
	
	/* Calculate output length */
	unsigned int n_chars = (int32_t)ceil(log((double)num) / log((double)output_base));
	if (num < 0) {
		n_chars++;
	}

	/* Check the output base and allocate space for prefixes */
	if (output_base < 2 || output_base > 16) {
		printf("Bad output base: %d\n", output_base);
		return 1;
	} else if (output_base == 16) {
		n_chars += 2;
	} else if (output_base == 8) {
		n_chars++;
	}

	char *output = calloc(n_chars, sizeof(char));
	char *w = output + n_chars;

	/* Working backwards, NUL-terminator */
	*(w--) = '\0';
	
	/* Working backwards, calculate and add the characters */
	while (num > 0) {
		int digit = num % output_base;
		*(w--) = reference_chars[digit];
		num /= output_base;
	}

	/* Add base-specific prefixes */
	if (output_base == 16) {
		*(w--) = 'x';
		*(w--) = '0';
	} else if (output_base == 8) {
		*(w--) = '0';
	}

	/* add the negative sign if necessary */
	if (num < 0) {
		*w = '-';
	}

	printf("Number: %d => %s\n", input_num, output);

	free(output);

	return 0;
}
