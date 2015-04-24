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

all: itao binary_sort strip_whitespace