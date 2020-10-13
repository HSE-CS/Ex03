#include "task1.h"
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <malloc.h>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iostream>
int comp(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}
void result()
{
    unsigned int* arr;
    unsigned int* arr_copy;
    arr = (unsigned int*)malloc(sizeof(unsigned int) * LARGE_SIZE);
    arr_copy = (unsigned int*)malloc(sizeof(unsigned int) * LARGE_SIZE);
    //int arr[LARGE_SIZE];
    //int arr_copy[LARGE_SIZE];
    // Рандомизация по таймеру
    for (unsigned int size = 100000; size <= LARGE_SIZE; size += 25000)
    {
        printf("size=%d\n", size);
        srand(time(nullptr));
        // генерируем случайные данные
        generate(arr, arr + size, rnd());
        copy(arr, arr + size, arr_copy);
        // засекаем время
        time_t start = clock();
        // выполняем сортировку, используя функцию qsort
        qsort(arr, size, sizeof(int), comp);
        cout << "C quick-sort time elapsed: " << static_cast<double>(clock() - start) / CLOCKS_PER_SEC << "\n";
        // снова засекаем время
        start = clock();
        // выполняем сортировку, используя алгоритм С++
        sort(arr_copy, arr_copy + size);
        cout << "C++ quick-sort time elapsed: " << static_cast<double>(clock() - start) / CLOCKS_PER_SEC << "\n";
    }
}