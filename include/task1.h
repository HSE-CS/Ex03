#ifndef Task1_H
#define Task1_H
const unsigned int LARGE_SIZE = 100000;
struct rnd {
    int operator()() {
        return rand() % LARGE_SIZE;
    }
};

int comp( const void* a, const void* b );

#endif
