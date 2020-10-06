#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "task1.h"
#include <stdlib.h>

using namespace std;


int main() {

    for (int i = 1; i <= 50; i++)
    {
        
        int* arr = (int*) malloc(LARGE_SIZE * i * sizeof(int));
        int* arr_copy = (int*) malloc(LARGE_SIZE * i * sizeof(int));

        cout << "Massive size: " << LARGE_SIZE * i << endl;

        // Рандомизация по таймеру
        srand(time(nullptr));

        // генерируем случайные данные
        generate(arr, arr + LARGE_SIZE * i, rnd());
        copy(arr, arr + LARGE_SIZE * i, arr_copy);

        // засекаем время
        time_t start = clock();

        // выполняем сортировку, используя функцию qsort
        qsort(arr, LARGE_SIZE * i, sizeof(int), comp);
        cout << "C quick-sort time elapsed: " << static_cast<double>(clock() - start) / CLOCKS_PER_SEC << "\n";

        // снова засекаем время
        start = clock();

        // выполняем сортировку, используя алгоритм С++
        sort(arr_copy, arr_copy + LARGE_SIZE * i);
        cout << "C++ quick-sort time elapsed: " << static_cast<double>(clock() - start) / CLOCKS_PER_SEC << "\n";
        cout << endl;
        free(arr);
        free(arr_copy);
    }

    return 0;
}