//
// Created by jmax on 22.09.2020.
//

#ifndef EX_03_TASK1_H
#define EX_03_TASK1_H

#include <iostream>
#include <algorithm>
#include <cstdlib>

const size_t LARGE_SIZE = 100000;

struct rnd {
    int operator()() {
        return rand() % LARGE_SIZE;
    }
};

int comp(const void *a, const void *b);

double qsort_time(int *arr, size_t size);

double sort_time(int *arr, size_t size);

#endif //EX_03_TASK1_H
