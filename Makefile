CC=g++
CFLAGS=-std=c++11 -O2 -Wall
TESTS=tests

subsets: subsets.cpp
	$(CC) $(CFLAGS) subsets.cpp -o subsets

permutations: permutations.cpp
	$(CC) $(CFLAGS) permutations.cpp -o permutations

max_subarray_sum: max_subarray_sum.o max_subarray_sum_tests.cpp
	$(CC) $(CFLAGS) max_subarray_sum_tests.cpp -o $(TESTS) max_subarray_sum.o

sorting: sorting.o sorting.cpp
	$(CC) $(CFLAGS) sorting_test.cpp -o $(TESTS) sorting.o