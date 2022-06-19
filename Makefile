CC=g++
CFLAGS=-std=c++11 -O2 -Wall

subsets: subsets.cpp
	$(CC) $(CFLAGS) subsets.cpp -o subsets

permutations: permutations.cpp
	$(CC) $(CFLAGS) permutations.cpp -o permutations

max_subarray_sum: max_subarray_sum.o max_subarray_sum_tests.cpp
	$(CC) $(CFLAGS) max_subarray_sum_tests.cpp -o tests max_subarray_sum.o