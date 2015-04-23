directories:
	mkdir -p build

itoa: directories
	gcc -g -lm -o build/itoa src/itoa.c

binary_sort: directories
	gcc -g -o build/binary_sort src/binary_sort.c

strip_whitespace: directories
	gcc -g -o build/strip_whitespace src/strip_whitespace.c
