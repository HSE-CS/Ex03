#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "task1.h"

using namespace std;

int main() {
    int arr[LARGE_SIZE];
    int arr_copy[LARGE_SIZE];

    for (int i = 0; i < 50; i++) {
        // Рандомизация по таймеру
        srand(time(nullptr));
        // генерируем случайные данные
        int LARGE_SIZE1 = 10000 + i * 1500;
        //cout << "Array size " << LARGE_SIZE1 << "\n";
        generate(arr, arr + LARGE_SIZE1, rnd());
        copy(arr, arr + LARGE_SIZE1, arr_copy);
        // засекаем время
        time_t start = clock();
        // выполняем сортировку, используя функцию qsort
        qsort(arr, LARGE_SIZE1, sizeof(int), comp);
        cout << LARGE_SIZE1 << ";" << static_cast<double>(clock() - start) / CLOCKS_PER_SEC << "\t";
        // снова засекаем время
        start = clock();
        // выполняем сортировку, используя алгоритм С++
        sort(arr_copy, arr_copy + LARGE_SIZE1);
        cout << LARGE_SIZE1 << ";" << static_cast<double>(clock() - start) / CLOCKS_PER_SEC << "\n";
    }
    return 0;
}