#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "task1.h"



int comp(const void* a, const void* b) {
	return (*(int*)a - *(int*)b);
}
