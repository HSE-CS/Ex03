#include "task1.h"
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <malloc.h>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iostream>
int comp(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}