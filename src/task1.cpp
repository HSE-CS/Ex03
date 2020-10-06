#include "task1.h"
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const size_t LARGE_SIZE = 100000;


int comp(const void* a, const void* b) {
	return (*(int*)a - *(int*)b);
}