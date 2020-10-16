#ifndef TASK1_H_INCLUDED
#define TASK1_H_INCLUDED

#include <cstdlib>

const int LARGE_SIZE = 200000;

struct rnd {
    int operator()() {
        return rand() % LARGE_SIZE;
    }
};

int comp( const void* a, const void* b );


#endif // TASK1_H_INCLUDED
