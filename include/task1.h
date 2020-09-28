//
// Created by kdash on 28.09.2020.
//

#ifndef TASK1_TASK1_H
#define TASK1_TASK1_H

#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const unsigned int LARGE_SIZE = 500000;

struct rnd {
    unsigned int operator()() {
        return rand() % LARGE_SIZE;
    }
};

int comp(const void* a, const void* b);
#endif //TASK1_TASK1_H
