CFLAGS = -g -std=gnu99 -lm
CC = gcc $(CFLAGS)

directories:
	mkdir -p build
	mkdir -p build/obj
	mkdir -p build/bin

atoi: directories
	$(CC) -o build/bin/atoi src/atoi.c

itoa: directories
	$(CC) -o build/bin/itoa src/itoa.c

binary_sort: directories
	$(CC) -o build/bin/binary_sort src/binary_sort.c

strip_whitespace: directories
	$(CC) -o build/bin/strip_whitespace src/strip_whitespace.c

fizzbuzz: directories
	$(CC) -o build/bin/fizzbuzz src/fizzbuzz.c

binary_search: directories
	$(CC) -o build/bin/binary_search src/binary_search.c

linked_list_reverse: directories
	$(CC) -o build/linked_list_reverse src/linked_list_reverse.c

sorting_algos: directories
	$(CC) -c -o build/obj/sort_bubble.o src/sort_bubble.c
	$(CC) -c -o build/obj/sort_heap.o src/sort_heap.c
	$(CC) -c -o build/obj/sort_insertion.o src/sort_insertion.c
	$(CC) -c -o build/obj/sort_merge.o src/sort_merge.c
	$(CC) -c -o build/obj/sort_quick.o src/sort_quick.c
	$(CC) -c -o build/obj/sort_selection.o src/sort_selection.c

sorting: directories sorting_algos
	$(CC) -c -o build/obj/sorting.o src/sorting.c
	$(CC) -o build/bin/sorting build/obj/sort_bubble.o build/obj/sort_heap.o build/obj/sort_insertion.o \
		build/obj/sort_merge.o build/obj/sort_quick.o build/obj/sort_selection.o build/obj/sorting.o

all: itao binary_sort strip_whitespace fizzbuzz sorting linked_list_reverse binary_search

