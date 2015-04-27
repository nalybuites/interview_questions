directories:
	mkdir -p build

atoi: directories
	gcc -g -lm -o build/atoi src/atoi.c

itoa: directories
	gcc -g -lm -o build/itoa src/itoa.c

binary_sort: directories
	gcc -g -o build/binary_sort src/binary_sort.c

strip_whitespace: directories
	gcc -g -o build/strip_whitespace src/strip_whitespace.c

fizzbuzz: directories
	gcc -g -std=gnu99 -o build/fizzbuzz src/fizzbuzz.c

binary_search: directories
	gcc -g -o build/binary_search src/binary_search.c

linked_list_reverse: directories
	gcc -g -std=gnu99 -o build/linked_list_reverse src/linked_list_reverse.c

sorting: directories
	gcc -g -std=gnu99 -o build/sorting src/sorting.c

all: itao binary_sort strip_whitespace fizzbuzz
