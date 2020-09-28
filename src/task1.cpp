#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "task1.h"

using namespace std;

int comp(const void* a, const void* b) {
	return (*(int*)a - *(int*)b);

