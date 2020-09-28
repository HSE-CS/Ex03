#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <iostream>
#include "task1.h"

using namespace std;

int main() {
    int arr[LARGE_SIZE];
    int arr_copy[LARGE_SIZE];
    // Рандомизация по таймеру
    srand(time(nullptr));
    for (int i = 2000; i < LARGE_SIZE; i += 2000) {
        // генерируем случайные данные
        generate(arr, arr + LARGE_SIZE, rnd());
        copy(arr, arr + LARGE_SIZE, arr_copy);
        // засекаем время
        time_t start = clock();
        // выполняем сортировку, используя функцию qsort
        qsort(arr, LARGE_SIZE, sizeof(int), comp);
        cout << "C quick-sort time elapsed: " << static_cast<double>(clock() - start) / CLOCKS_PER_SEC << ";";
        // снова засекаем время
        start = clock();
        // выполняем сортировку, используя алгоритм С++
        sort(arr_copy, arr_copy + LARGE_SIZE);
        cout << "C++ quick-sort time elapsed: " << static_cast<double>(clock() - start) / CLOCKS_PER_SEC << "\n";
    }
    return 0;
}