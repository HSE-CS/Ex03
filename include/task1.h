#ifndef TASK1_H
#define TASK1_H
#include <cstdlib>

const size_t LARGE_SIZE = 10000;
struct rnd
{
	int operator()()
	{
		return rand() % LARGE_SIZE;
	}
};
int comp(const void* a, const void* b);
void check();
#endif