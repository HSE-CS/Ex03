#ifndef TASK3_H
#define TASK3_H
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <ctime>

const size_t LARGE_SIZE =100000;

struct rnd {
    int operator()() {
        return rand() % LARGE_SIZE;
    }
};

int comp(const void* a, const void* b);

#endif