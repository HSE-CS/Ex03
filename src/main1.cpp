#include "../include/task1.h"
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    for (int i = LARGE_SIZE / 50; i <= LARGE_SIZE; i = i + LARGE_SIZE / 50)
    {
        int *arr = new int[i];
        int *arr_copy = new int[i];
        // Рандомизация по таймеру
        srand(time(nullptr));
        // генерируем случайные данные
        generate(arr, arr + i, rnd());
        copy(arr, arr + i, arr_copy);
        // засекаем время
        time_t start = clock();
        // выполняем сортировку, используя функцию qsort
        qsort(arr, i, sizeof(int), comp);
        cout << i << "|" << static_cast<double>(clock() - start) / CLOCKS_PER_SEC;
        // снова засекаем время
        start = clock();
        // выполняем сортировку, используя алгоритм С++
        sort(arr_copy, arr_copy + i);
        cout << "|" << static_cast<double>(clock() - start) / CLOCKS_PER_SEC << "\n";
        free(arr);
        free(arr_copy);
    }
    return 0;
} 