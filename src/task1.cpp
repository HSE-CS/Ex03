#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <ctime>

#include "task1.h"

using namespace std;

const size_t LARGE_SIZE = 100000;

struct rnd {
    int operator()() {
        return rand() % LARGE_SIZE;
    }
};


int comp(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}
