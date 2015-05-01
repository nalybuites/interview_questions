#include <stdbool.h>
#include <stdio.h>

#include "../include/fizzbuzz.h"

const char *
fizzbuzz(unsigned int num)
{

	if (num % 3 == 0 && num % 5 == 0) {
		return "FizzBuzz";
	}

	if (num % 3 == 0) {
		return "Fizz";
	}

	if (num % 5 == 0) {
		return "Buzz";
	}

	return NULL;
}

