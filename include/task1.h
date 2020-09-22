#pragma once
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <ctime>

const size_t LARGE_SIZE = 100000;

const size_t DELTA_SIZE = 1000;

struct rnd 
{
    int operator()()
    {
        return rand() % LARGE_SIZE;
    }
};

int comp(const void* a, const void* b);
