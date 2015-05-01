#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "../include/itoa.h"
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
	bool is_negative = (num < 0);

	/* Calculate output length */
	num = abs(num);
	n_chars = (int32_t)ceil(log((double)num) / log((double)base));
	if (is_negative) {
		n_chars++;
	}

	/* Check the output base and allocate space for prefixes */
	if (base < 2 || base > 16) {
		return NULL;
	} else if (base == 2 || base == 16) {
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
	if (base == 2) {
		*(w--) = 'b';
		*(w--) = '0';
	} else if (base == 16) {
		*(w--) = 'x';
		*(w--) = '0';
	} else if (base == 8) {
		*(w--) = '0';
	}

	/* add the negative sign if necessary */
	if (is_negative) {
		*w = '-';
	}

	return output;
}

