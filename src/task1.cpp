//
// Created by jmax on 22.09.2020.
//
#include "task1.h"

double sort_time(int *arr, size_t size) {
    time_t start = clock();
    std::sort(arr, arr + size);
    return static_cast<double>(clock() - start);
}


int comp(const void *a, const void *b) {
    return (*(int *) a - *(int *) b);
}

double qsort_time(int *arr, size_t size) {
    time_t start = clock();
    qsort(arr, size, sizeof(int), comp);
    return static_cast<double>(clock() - start);
}