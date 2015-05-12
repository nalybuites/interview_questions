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

/* Thread context, gives the thread worker function all the information it
 * needs, plus thread ID for debugging.
 */
struct context {
	size_t thread_id;
	uint32_t *data;
	size_t start;
	size_t end;
	uint64_t *subtotal;
};

/* Thread worker function. Iterates from the context start to end and adds up
 * the integers it sees and stores the subtotal in the provided location.
 */
void *
subtotal_calculate(void *x)
{
	struct context *c = (struct context *)x;
	size_t i;
	uint64_t num = 0;

	for (i = c->start; i <= c->end; i++) {
		num += c->data[i];
	}

	*(c->subtotal) = num;

	pthread_exit(NULL);
}

int
main(int argc, char *argv[])
{
	int fd;
	unsigned int n_cpu_core = sysconf(_SC_NPROCESSORS_ONLN);
	unsigned int n_threads = n_cpu_core - 1;
	const char *filename = argv[1];
	uint32_t *mapped_numbers;
	uint64_t total = 0, n_ints = 0, slice_len = 0;
	pthread_t threads[n_threads];
	pthread_attr_t attr;
	uint64_t subtotal[n_threads];
	int return_codes[n_threads];
	struct context *contexts[n_threads];
	size_t i;

	fd = open(filename, O_RDONLY);
	if (fd == -1) {
		error("Failed to open fd");
	}

	/* Need the file size */
	struct stat st;
	if (stat(filename, &st) != 0) {
		close(fd);
		error ("Failed to stat file");
	}

	/* Since we know the file contains unsigned 32-bit ints, we can safely
	 * divide to determine the number of integers to add up.
	 */
	n_ints = st.st_size / sizeof(uint32_t);
	slice_len = n_ints / n_threads;

	mapped_numbers = mmap(0, st.st_size, PROT_READ, MAP_SHARED, fd, 0);
	if (mapped_numbers == MAP_FAILED) {
		close(fd);
		error("Failed to map file");
	}
	madvise(mapped_numbers, st.st_size, MADV_SEQUENTIAL | MADV_WILLNEED);

	pthread_attr_init(&attr);
	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);
	for (i = 0; i < n_threads; i++) {
		contexts[i] = calloc(1, sizeof(struct context));

		contexts[i]->thread_id = i;
		contexts[i]->data = mapped_numbers;
		contexts[i]->start = i * slice_len;
		contexts[i]->end = contexts[i]->start + slice_len - 1;
		contexts[i]->subtotal = &subtotal[i];

		if (i == n_threads - 1) {
			/* If this is the last thread, it needs to pick up the
			 * slack of the other threads. Since the number of ints
			 * in the file is not guarateed to be divisible by the
			 * number of threads, we need to account for the missing
			 * ints here.
			 */
			contexts[i]->end += n_ints % n_threads;
		}

		return_codes[i] = pthread_create(&threads[i], &attr, subtotal_calculate, (void *)contexts[i]);
	}

	void *status = NULL;
	pthread_attr_destroy(&attr);
	for (i = 0; i < n_threads; i++) {
		/* Join the threads and grab the subtotals */
		pthread_join(threads[i], status);
		total += subtotal[i];

		free(contexts[i]);
	}

	munmap(mapped_numbers, st.st_size);

	printf("total: %" PRIu64"\n", total);

	pthread_exit(NULL);

	return 0;
}

