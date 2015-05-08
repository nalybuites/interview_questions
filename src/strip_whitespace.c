#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "../include/strip_whitespace.h"

/*
 * strip_whitespace: Remove any unnecessary white space in the provided string.
 * This involves removing duplicate spaces, converting tabs to spaces.
 */
char *
strip_whitespace(const char *input)
{
	unsigned int n_chars;
	const char *read;
	char *write;
	char *output;

	if (input == NULL) {
		return NULL;
	}

	n_chars = strlen(input);
	if (n_chars == 0) {
		return NULL;
	}

	output = calloc(n_chars + 1, sizeof(char));
	read = input;
	write = output;

	while (*read != '\0') {
		if ((*read == ' ' || *read == '\t') &&
		    (*(read + 1) == ' ' || *(read + 1) == '\t')) {
			read++;
			continue;
		}
		
		if (*read == '\t') {
			*(write++) = ' ';
			read++;
		} else {
			*(write++) = *(read++);
		}
	}

	return output;
}

