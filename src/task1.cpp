#include <iostream>
#include <cstdlib>
#include "task1.h"


int comp(const void* a, const void* b) {
	return (*(int*)a - *(int*)b);
}