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
	int fd;
	const char *filename = argv[1];
	uint32_t *mapped_numbers;
	uint64_t total = 0;
	uint64_t n_ints = 0;

	fd = open(filename, O_RDONLY);
	if (fd == -1) {
		error("Failed to open fd");
	}

	struct stat st;
	if (stat(filename, &st) != 0) {
		close(fd);
		error ("Failed to stat file");
	}

	n_ints = st.st_size / sizeof(uint32_t);

	mapped_numbers = mmap(0, st.st_size, PROT_READ, MAP_SHARED, fd, 0);
	if (mapped_numbers == MAP_FAILED) {
		close(fd);
		error("Failed to map file");
	}
	madvise(mapped_numbers, st.st_size, MADV_SEQUENTIAL | MADV_WILLNEED);

	size_t i;
	for (i = 0; i < n_ints; i++) {
		total += mapped_numbers[i];
	}

	munmap(mapped_numbers, st.st_size);

	printf("total: %" PRIu64"\n", total);

	return 0;
}

