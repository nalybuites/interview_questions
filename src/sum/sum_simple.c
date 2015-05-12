#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <inttypes.h>
#include <unistd.h>
#include <pthread.h>

#define error(msg) do {\
	perror(msg);\
	exit(EXIT_FAILURE);\
	} while (0)

int
main(int argc, char *argv[])
{

	const char *filename = argv[1];
	uint64_t total = 0;

	FILE *file = fopen(filename, "r");
	if (file == NULL) {
		error("Failed to open fd");
	}

	uint32_t num;
	while (fread(&num, sizeof(uint32_t), 1, file)) {
		total += num;
	}

	printf("total: %" PRIu64"\n", total);

	return 0;
}

