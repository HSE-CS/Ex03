#include "task1.h"
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
int main() {
    int arr[LARGE_SIZE];
    int arr_copy[LARGE_SIZE];
    int n;
    cin >> n;
    int size = 1000;

    for (int i = 0; i < n; i++)
    {
        // Рандомизация по таймеру
        srand(time(nullptr));
        // генерируем случайные данные
        generate(arr, arr + size, rnd());
        copy(arr, arr + size, arr_copy);
        // засекаем время
        time_t start = clock();
        // выполняем сортировку, используя функцию qsort
        qsort(arr, size, sizeof(int), comp);
        // C, C++
        cout << size << " " << static_cast<double>(clock() - start) / CLOCKS_PER_SEC << " " << static_cast<double>(clock() - start) / CLOCKS_PER_SEC << "\n";
        // снова засекаем время
        start = clock();
        // выполняем сортировку, используя алгоритм С++
        sort(arr_copy, arr_copy + size);
        // cout  << static_cast<double>(clock() - start) / CLOCKS_PER_SEC << "\n";
        // cout << "\n";
        size = size + 20000;
    }

    return 0;
}