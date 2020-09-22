//
// Created by toliman on 22.09.2020.
//

#ifndef EX03_TASK1_H
#define EX03_TASK1_H


const size_t LARGE_SIZE = 100000;


struct rnd {
    int operator()() {
        return rand() % LARGE_SIZE;
    }
};

int comp(const void *a, const void *b);

#endif //EX03_TASK1_H
