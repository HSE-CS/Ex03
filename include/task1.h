#ifndef EX03_TASK1_H
#define EX03_TASK1_H
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const size_t LARGE_SIZE = 100000;

struct rnd 
{
	int operator()() 
	{
		return rand() % LARGE_SIZE;
	}
};
int comp(const void *a, const void *b);
#endif 
