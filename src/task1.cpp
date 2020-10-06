#include "task1.h"
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int comp(const void* a, const void* b) {
	return (*(int*)a - *(int*)b);
}
