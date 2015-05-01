CFLAGS = -g -std=gnu99 -lm
CC = gcc $(CFLAGS)

directories:
	mkdir -p build
	mkdir -p build/obj
	mkdir -p build/bin
	mkdir -p build/check

clean :
	rm -rf build

atoi : directories
	$(CC) -c -o build/obj/atoi.o src/atoi.c

itoa : directories
	$(CC) -o build/bin/itoa.o src/itoa.c

binary_sort : directories
	$(CC) -c -o build/obj/binary_sort.o src/binary_sort.c

strip_whitespace : directories
	$(CC) -o build/bin/strip_whitespace src/strip_whitespace.c

fizzbuzz : directories
	$(CC) -c -o build/obj/fizzbuzz.o src/fizzbuzz.c

binary_search : directories
	$(CC) -o build/bin/binary_search src/binary_search.c

linked_list_reverse : directories
	$(CC) -o build/bin/linked_list_reverse src/linked_list_reverse.c

sorting_algos : directories
	$(CC) -c -o build/obj/sort_bubble.o src/sort_bubble.c
	$(CC) -c -o build/obj/sort_heap.o src/sort_heap.c
	$(CC) -c -o build/obj/sort_insertion.o src/sort_insertion.c
	$(CC) -c -o build/obj/sort_merge.o src/sort_merge.c
	$(CC) -c -o build/obj/sort_quick.o src/sort_quick.c
	$(CC) -c -o build/obj/sort_selection.o src/sort_selection.c

sorting : directories sorting_algos
	$(CC) -c -o build/obj/sorting.o src/sorting.c
	$(CC) -o build/bin/sorting build/obj/sort_bubble.o build/obj/sort_heap.o build/obj/sort_insertion.o \
		build/obj/sort_merge.o build/obj/sort_quick.o build/obj/sort_selection.o build/obj/sorting.o
check : all
	gcc -g -std=gnu99 -lcheck -o build/check/check_atoi build/obj/atoi.o test/check_atoi.c
	gcc -g -std=gnu99 -lcheck -o build/check/check_binary_sort build/obj/binary_sort.o test/check_binary_sort.c
	gcc -g -std=gnu99 -lcheck -o build/check/check_fizzbuzz build/obj/fizzbuzz.o test/check_fizzbuzz.c

all : itoa binary_sort strip_whitespace fizzbuzz sorting linked_list_reverse binary_search atoi

