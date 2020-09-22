#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "task1.h"

using namespace std;

const size_t LARGE_SIZE = 100000;

int main() {
    int arr[LARGE_SIZE];
    int arr_copy[LARGE_SIZE];
    // Рандомизация по таймеру
    srand(time(nullptr));
    // генерируем случайные данные
    generate(arr, arr + LARGE_SIZE, rnd());
    copy(arr, arr + LARGE_SIZE, arr_copy);
    // засекаем время

    cout << "quick-sort size / time" << endl;
    int size[1000] = {100};
    for (int i = 0; i < 1000; i++) {
        if (i != 0)
            size[i] = size[i - 1] + 100;

        time_t start = clock();
        // выполняем сортировку, используя функцию qsort
        qsort(arr, size[i], sizeof(int), comp);
        cout << static_cast<double>(clock() - start) / CLOCKS_PER_SEC << "\n";
    }

    cout << "C++ quick-sort size/time elapsed" << endl;

    for (int i = 0; i < 1000; i++) {
        time_t start = clock();
        // выполняем сортировку, используя алгоритм С++
        sort(arr_copy, arr_copy + size[i]);
        cout << static_cast<double>(clock() - start) / CLOCKS_PER_SEC << "\n";
    }

    cout << "SIZE-----------" << endl;
    for (auto el : size)
        cout << el << endl;

    
    return 0;
}