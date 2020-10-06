//
// Created by Vadim Makarov on 22.09.2020.
//

#ifndef TASK1_TASK1_H
#define TASK1_TASK1_H

#include <cstdlib>

const size_t LARGE_SIZE = 1000000;

struct rnd {
    int operator()() {
        return rand() % LARGE_SIZE;
    }
};

int comp( const void* a, const void* b );
int measure();


#endif //TASK1_TASK1_H
