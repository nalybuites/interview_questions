CFLAGS = -g -std=gnu99 -lm -lcheck
CC = gcc $(CFLAGS)
BUILD_DIR = build
OBJ_DIR = $(BUILD_DIR)/obj
CHECK_DIR = $(BUILD_DIR)/check
BIN_DIR = $(BUILD_DIR)/bin
SRC_DIR = src
TEST_DIR = test

directories :
	mkdir -p $(BUILD_DIR)
	mkdir -p $(OBJ_DIR)
	mkdir -p $(BIN_DIR)
	mkdir -p $(CHECK_DIR)

clean :
	rm -rf $(BUILD_DIR)

atoi : directories
	$(CC) -c -o $(OBJ_DIR)/atoi.o $(SRC_DIR)/atoi.c

itoa : directories
	$(CC) -c -o $(OBJ_DIR)/itoa.o $(SRC_DIR)/itoa.c

binary_sort : directories
	$(CC) -c -o $(OBJ_DIR)/binary_sort.o $(SRC_DIR)/binary_sort.c

int_set_intersect : directories
	$(CC) -c -o $(OBJ_DIR)/int_set_intersect.o $(SRC_DIR)/int_set_intersect.c

strip_whitespace : directories
	$(CC) -c -o $(OBJ_DIR)/strip_whitespace.o $(SRC_DIR)/strip_whitespace.c

fizzbuzz : directories
	$(CC) -c -o $(OBJ_DIR)/fizzbuzz.o $(SRC_DIR)/fizzbuzz.c
fibonacci : directories
	$(CC) -c -o $(OBJ_DIR)/fibonacci.o $(SRC_DIR)/fibonacci.c

binary_search : directories
	$(CC) -c -o $(OBJ_DIR)/binary_search.o $(SRC_DIR)/binary_search.c

linked_list_reverse : directories
	$(CC) -c -o $(OBJ_DIR)/linked_list_reverse.o $(SRC_DIR)/linked_list_reverse.c

sum_array : directories
	$(CC) -c -o $(OBJ_DIR)/sum_array.o $(SRC_DIR)/sum_array.c

list_merge : directories
	$(CC) -c -o $(OBJ_DIR)/list_merge.o $(SRC_DIR)/list_merge.c

sorting : directories
	$(CC) -c -o $(OBJ_DIR)/sort_bubble.o $(SRC_DIR)/sort/sort_bubble.c
	$(CC) -c -o $(OBJ_DIR)/sort_heap.o $(SRC_DIR)/sort/sort_heap.c
	$(CC) -c -o $(OBJ_DIR)/sort_insertion.o $(SRC_DIR)/sort/sort_insertion.c
	$(CC) -c -o $(OBJ_DIR)/sort_merge.o $(SRC_DIR)/sort/sort_merge.c
	$(CC) -c -o $(OBJ_DIR)/sort_quick.o $(SRC_DIR)/sort/sort_quick.c
	$(CC) -c -o $(OBJ_DIR)/sort_selection.o $(SRC_DIR)/sort/sort_selection.c

check : all
	$(CC) -o $(CHECK_DIR)/check_atoi \
		$(OBJ_DIR)/atoi.o \
		$(TEST_DIR)/check_atoi.c
	$(CC) -o $(CHECK_DIR)/check_binary_sort \
		$(OBJ_DIR)/binary_sort.o \
		$(TEST_DIR)/check_binary_sort.c
	$(CC) -o $(CHECK_DIR)/check_fizzbuzz \
		$(OBJ_DIR)/fizzbuzz.o \
		$(TEST_DIR)/check_fizzbuzz.c
	$(CC) -o $(CHECK_DIR)/check_strip_whitespace \
		$(OBJ_DIR)/strip_whitespace.o \
		$(TEST_DIR)/check_strip_whitespace.c
	$(CC) -o $(CHECK_DIR)/check_binary_search \
		$(OBJ_DIR)/binary_search.o \
		$(TEST_DIR)/check_binary_search.c
	$(CC) -o $(CHECK_DIR)/check_linked_list_reverse \
		$(OBJ_DIR)/linked_list_reverse.o \
		$(TEST_DIR)/check_linked_list_reverse.c
	$(CC) -o $(CHECK_DIR)/check_itoa \
		$(OBJ_DIR)/itoa.o \
		$(TEST_DIR)/check_itoa.c
	$(CC) -o $(CHECK_DIR)/check_sorting \
		$(OBJ_DIR)/sort_bubble.o \
		$(OBJ_DIR)/sort_heap.o \
		$(OBJ_DIR)/sort_insertion.o \
		$(OBJ_DIR)/sort_merge.o \
		$(OBJ_DIR)/sort_quick.o \
		$(OBJ_DIR)/sort_selection.o \
		$(TEST_DIR)/check_sorting.c
	$(CC) -o $(CHECK_DIR)/check_int_set_intersect \
		$(OBJ_DIR)/int_set_intersect.o \
		$(TEST_DIR)/check_int_set_intersect.c
	$(CC) -o $(CHECK_DIR)/check_sum_array \
		$(OBJ_DIR)/sum_array.o \
		$(TEST_DIR)/check_sum_array.c
	$(CC) -o $(CHECK_DIR)/check_list_merge \
		$(OBJ_DIR)/list_merge.o \
		$(TEST_DIR)/check_list_merge.c
	$(CC) -o $(CHECK_DIR)/check_fibonacci \
		$(OBJ_DIR)/fibonacci.o \
		$(TEST_DIR)/check_fibonacci.c

all : itoa binary_sort strip_whitespace fizzbuzz sorting linked_list_reverse binary_search atoi int_set_intersect sum_array list_merge fibonacci

