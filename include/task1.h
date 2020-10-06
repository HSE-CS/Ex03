
#include <iostream>
struct rnd {
	const int LARGE_SIZE = 100000;
    int operator()() {
        return rand() % LARGE_SIZE;
    }
};

int comp( const void* a, const void* b );
void realizesort();
