CFLAGS = -g -std=gnu99 -lm
CC = gcc $(CFLAGS)

directories :
	mkdir -p build
	mkdir -p build/obj
	mkdir -p build/bin
	mkdir -p build/check

clean :
	rm -rf build

atoi : directories
	$(CC) -c -o build/obj/atoi.o src/atoi.c

itoa : directories
	$(CC) -c -o build/obj/itoa.o src/itoa.c

binary_sort : directories
	$(CC) -c -o build/obj/binary_sort.o src/binary_sort.c

int_set_intersect : directories
	$(CC) -c -o build/obj/int_set_intersect.o src/int_set_intersect.c

strip_whitespace : directories
	$(CC) -c -o build/obj/strip_whitespace.o src/strip_whitespace.c

fizzbuzz : directories
	$(CC) -c -o build/obj/fizzbuzz.o src/fizzbuzz.c
fibonacci : directories
	$(CC) -c -o build/obj/fibonacci.o src/fibonacci.c

binary_search : directories
	$(CC) -c -o build/obj/binary_search.o src/binary_search.c

linked_list_reverse : directories
	$(CC) -c -o build/obj/linked_list_reverse.o src/linked_list_reverse.c

sum_array : directories
	$(CC) -c -o build/obj/sum_array.o src/sum_array.c

list_merge : directories
	$(CC) -c -o build/obj/list_merge.o src/list_merge.c

largest_int : directories
	$(CC) -c -o build/obj/largest_int.o src/largest_int.c

sorting : directories
	$(CC) -c -o build/obj/sort_bubble.o src/sort_bubble.c
	$(CC) -c -o build/obj/sort_heap.o src/sort_heap.c
	$(CC) -c -o build/obj/sort_insertion.o src/sort_insertion.c
	$(CC) -c -o build/obj/sort_merge.o src/sort_merge.c
	$(CC) -c -o build/obj/sort_quick.o src/sort_quick.c
	$(CC) -c -o build/obj/sort_selection.o src/sort_selection.c

check : all
	gcc -g -std=gnu99 -lcheck -o build/check/check_atoi build/obj/atoi.o test/check_atoi.c
	gcc -g -std=gnu99 -lcheck -o build/check/check_binary_sort build/obj/binary_sort.o test/check_binary_sort.c
	gcc -g -std=gnu99 -lcheck -o build/check/check_fizzbuzz build/obj/fizzbuzz.o test/check_fizzbuzz.c
	gcc -g -std=gnu99 -lcheck -o build/check/check_strip_whitespace build/obj/strip_whitespace.o test/check_strip_whitespace.c
	gcc -g -std=gnu99 -lcheck -o build/check/check_binary_search build/obj/binary_search.o test/check_binary_search.c
	gcc -g -std=gnu99 -lcheck -o build/check/check_linked_list_reverse build/obj/linked_list_reverse.o test/check_linked_list_reverse.c
	gcc -g -std=gnu99 -lcheck -lm -o build/check/check_itoa build/obj/itoa.o test/check_itoa.c
	gcc -g -std=gnu99 -lcheck -lm -o build/check/check_sorting build/obj/sort_bubble.o build/obj/sort_heap.o build/obj/sort_insertion.o build/obj/sort_merge.o build/obj/sort_quick.o build/obj/sort_selection.o test/check_sorting.c
	gcc -g -std=gnu99 -lcheck -lm -o build/check/check_int_set_intersect build/obj/int_set_intersect.o test/check_int_set_intersect.c
	gcc -g -std=gnu99 -lcheck -lm -o build/check/check_sum_array build/obj/sum_array.o test/check_sum_array.c
	gcc -g -std=gnu99 -lcheck -lm -o build/check/check_list_merge build/obj/list_merge.o test/check_list_merge.c
	gcc -g -std=gnu99 -lcheck -lm -o build/check/check_fibonacci build/obj/fibonacci.o test/check_fibonacci.c
	gcc -g -std=gnu99 -lcheck -lm -o build/check/check_largest_int build/obj/largest_int.o test/check_largest_int.c

all : itoa binary_sort strip_whitespace fizzbuzz sorting linked_list_reverse binary_search atoi int_set_intersect sum_array list_merge fibonacci largest_int

