//
// Created by toliman on 22.09.2020.
//

#ifndef EX03_TASK1_H
#define EX03_TASK1_H


struct rnd {
    int operator()() {
        return rand() % 100000;
    }
};

int comp(const void *a, const void *b);

#endif //EX03_TASK1_H
