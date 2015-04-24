#include <math.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int
main(int argc, char **argv)
{
	
	if (argc < 2) {
		printf("Missing args\n");
		return 1;
	}

	const char *input = argv[1];
	if (input == NULL) {
		printf("Bad input\n");
		return 1;
	}

	unsigned int n_chars = strlen(input);
	if (n_chars == 0) {
		printf("Bad input\n");
		return 1;
	}

	const char *read = input;

	/* Trim whitespace from the front */
	while(isblank(*read)) {
		read++;
	}

	bool is_negative = false;
	if (*read == '-') {
		read++;
		is_negative = true;
	}

	const char *last_digit = read;
	while (isdigit(*last_digit)) {
		last_digit++;
	}
	last_digit--;
	int num = 0;
	unsigned int factor = 1;

	/* Find the end of the parsable string */
	while (last_digit >= read) {
		num += (int)(*last_digit - '0') * factor;
		factor *= 10;
		last_digit--;
	}

	if (is_negative) {
		num *= -1;
	}

	printf("atoi: %s => %d\n", input, num);

	return 0;
}
