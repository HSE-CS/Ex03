#ifndef TASK1_H
#define TASK1_H
#include <cstdlib>
using namespace std;

const size_t LARGE_SIZE = 100000;



struct rnd {
    int operator()() {
       // return rand() % LARGE_SIZE;
        return rand() % LARGE_SIZE;
    }
};

int comp(const void* a, const void* b);
void result();
#endif