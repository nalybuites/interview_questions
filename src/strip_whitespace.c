#include <malloc.h>
#include <stdio.h>
#include <string.h>


/*
 * strip_whitespace: Remove any unnecessary white space in the provided string.
 * This involves removing duplicate spaces, converting tabs to spaces.
 */
int
main(int argc, char **argv)
{

	if (argc < 2) {
		printf("Missing args\n");
		return 1;
	}

	const char *input = argv[1];
	unsigned int n_chars = strlen(input);
	char *output = calloc(n_chars + 1, sizeof(char));

	const char *read = input;
	char *write = output;

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

	printf("strip_whitespace: %s => %s\n", input, output);
	
	free(output);

	return 0;
}
