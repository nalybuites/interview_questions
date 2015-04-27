#include <math.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int
int_atoi(const char *input)
{
	unsigned int n_chars;
	unsigned int factor = 1;
	int num = 0;
	const char *read;
	const char *last_digit;
	bool is_negative = false;

	if (input == NULL) {
		return 0;
	}

	n_chars = strlen(input);
	if (n_chars == 0) {
		return 0;
	}

	read = input;

	/* Trim whitespace from the front */
	while(isblank(*read)) {
		read++;
	}

	if (*read == '-') {
		read++;
		is_negative = true;
	}

	last_digit = read;
	while (isdigit(*last_digit)) {
		last_digit++;
	}
	last_digit--;

	/* Find the end of the parsable string */
	while (last_digit >= read) {
		num += (int)(*last_digit - '0') * factor;
		factor *= 10;
		last_digit--;
	}

	if (is_negative) {
		num *= -1;
	}

	return num;

}

int
main(int argc, char **argv)
{
	
	if (argc < 2) {
		printf("Missing args\n");
		return 1;
	}

	const char *input = argv[1];
	int num = int_atoi(input);

	printf("atoi: %s => %d\n", input, num);

	return 0;
}
