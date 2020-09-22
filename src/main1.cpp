#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <ctime>

#include "task1.h"

using namespace std;
const size_t LARGE_SIZE = 100000;

struct rnd
{
    int operator()() {
        return rand() % LARGE_SIZE;
    }
};

int main()
{
    // Рандомизация по таймеру
    srand(time(nullptr));

    for (int iter = 1; iter < 51; iter++)
    {
        size_t ARR_SIZE = 50000 * iter;
        cout << iter << " " << ARR_SIZE/1000 << " ";

        int* arr = (int*)calloc(ARR_SIZE, sizeof(int));
        int* arr_copy = (int*)calloc(ARR_SIZE, sizeof(int));

        // генерируем случайные данные
        generate(arr, arr + ARR_SIZE, rnd());
        copy(arr, arr + ARR_SIZE, arr_copy);

        // засекаем время
        time_t start = clock();

        // выполняем сортировку, используя функцию qsort
        qsort(arr, ARR_SIZE, sizeof(int), comp);
        cout << static_cast<double>(clock() - start) / CLOCKS_PER_SEC << " ";

        // снова засекаем время
        start = clock();

        // выполняем сортировку, используя алгоритм С++
        sort(arr_copy, arr_copy + ARR_SIZE);
        cout << static_cast<double>(clock() - start) / CLOCKS_PER_SEC << "\n";

        free(arr);
        free(arr_copy);
    }

    return 0;
}