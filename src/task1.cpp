#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <ctime>

int comp(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}