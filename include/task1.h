//
//  task1.h
//  task1
//
//  Created by Julia Rogozyan on 05.10.2020.
//  Copyright © 2020 Julia Rogozyan. All rights reserved.
//

#include <cstdlib>

const size_t LARGE_SIZE = 100000;

struct rnd {
    int operator()() {
        return rand() % LARGE_SIZE;
    }
};


int comp( const void* a, const void* b );
