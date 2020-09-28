#ifndef TASK1_H
#define TASK1_H

const size_t LARGE_SIZE = 100000;

struct rnd {
	int operator()() {
		return rand() % 100000;
	}
};

int comp(const void* a, const void* b);




#endif 