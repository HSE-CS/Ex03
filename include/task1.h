#pragma once

#include<cstdlib>
#include <ctime>

const size_t LARGE_SIZE = 102000;

int comp(const void* a, const void* b);

struct rnd {
	int operator()() {
		return rand() % LARGE_SIZE;
	}
};
