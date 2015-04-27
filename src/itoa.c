#include <math.h>
#include <stdio.h>
#include <stdlib.h>

/*
 * Traditional itoa() implementation
 */
char *
int_itoa(int num, int base)
{
	char *reference_chars = "0123456789abcdef";
	unsigned int n_chars;
	char *output;
	char *w;

	/* Calculate output length */
	n_chars = (int32_t)ceil(log((double)num) / log((double)base));
	if (num < 0) {
		n_chars++;
	}

	/* Check the output base and allocate space for prefixes */
	if (base < 2 || base > 16) {
		return NULL;
	} else if (base == 16) {
		n_chars += 2;
	} else if (base == 8) {
		n_chars++;
	}

	output = calloc(n_chars, sizeof(char));
	w = output + n_chars;

	/* Working backwards, NUL-terminator */
	*(w--) = '\0';
	
	/* Working backwards, calculate and add the characters */
	while (num > 0) {
		int digit = num % base;
		*(w--) = reference_chars[digit];
		num /= base;
	}

	/* Add base-specific prefixes */
	if (base == 16) {
		*(w--) = 'x';
		*(w--) = '0';
	} else if (base == 8) {
		*(w--) = '0';
	}

	/* add the negative sign if necessary */
	if (num < 0) {
		*w = '-';
	}

	return output;
}

int
main(int argc, char **argv)
{
	if (argc < 3) {
		printf("Missing args\n");
		return 1;
	}

	int input_num = (argv[0] == NULL) ? 0 : strtol(argv[1], NULL, 10);
	int output_base = (argv[1] == NULL) ? 10 : strtol(argv[2], NULL, 10);

	if (output_base < 2 || output_base > 16) {
		printf("Bad output base: %d\n", output_base);
		return 1;
	}
	char *output = int_itoa(input_num, output_base);
	printf("Number: %d => %s\n", input_num, output);

	free(output);

	return 0;
}
