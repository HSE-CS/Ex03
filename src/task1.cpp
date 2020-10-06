#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int comp(const void* a, const void* b) {
	return (*(int*)a - *(int*)b);
}