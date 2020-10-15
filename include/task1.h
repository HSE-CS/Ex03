#ifndef task1
#define task1
#include <iostream>

const size_t LARGE_SIZE = 500000;

struct rnd {
	int operator()() {
		return rand() % LARGE_SIZE;
	}
};



int comp(const void* a, const void* b);
#endif 