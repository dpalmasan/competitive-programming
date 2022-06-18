CC=g++
CFLAGS=-std=c++11 -O2 -Wall

subsets: subsets.cpp
	$(CC) $(CFLAGS) subsets.cpp -o subsets

permutations: permutations.cpp
	$(CC) $(CFLAGS) permutations.cpp -o permutations