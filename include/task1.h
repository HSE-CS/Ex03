//#pragma once
#include <cstdlib>
int comp( const void* a, const void* b );

const size_t LARGE_SIZE = 100000;

struct rnd {
    int operator()() {
        return rand() % LARGE_SIZE;
    }
};