#include <stdbool.h>
#include <stdio.h>

void
fizzbuzz(unsigned int limit)
{
	bool printed;

	for (unsigned int i = 0; i < limit; i++) {
		printed = false;

		if (i % 3 == 0) {
			printf("Fizz");
			printed = true;
		}

		if (i % 5 == 0) {
			printf("Buzz");
			printed = true;
		}

		if (printed) {
			printf("\n");
		}
	}
}

int
main(int argc, char **argv)
{
	fizzbuzz(100);

	return 0;
}

