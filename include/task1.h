#ifndef TASK1_H
#define TASK1_H

#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <ctime>

int comp(const void* a, const void* b);

const size_t LARGE_SIZE = 100000;

struct rnd {
    int operator()() {
        return rand() % LARGE_SIZE;
    }
};

#endif TASK1_H