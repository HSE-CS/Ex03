#include "task1.h"
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    
    int arr[LARGE_SIZE];
    int arr_copy[LARGE_SIZE];
    // Рандомизация по таймеру
    srand(time(nullptr));
    unsigned int SIZE = 1000;
    for (int i = 0; i < 50; i++)
    {
        // генерируем случайные данные
        generate(arr, arr + SIZE, rnd());
        copy(arr, arr + SIZE, arr_copy);
        // засекаем время
        time_t start = clock();
        // выполняем сортировку, используя функцию qsort
        qsort(arr, SIZE, sizeof(int), comp);
        //cout << "C quick-sort time elapsed: " << static_cast<double>(clock() - start) / CLOCKS_PER_SEC << "\n";
        //cout << SIZE << " " << static_cast<double>(clock() - start) / CLOCKS_PER_SEC << "\n";
        // снова засекаем время
        start = clock();
        // выполняем сортировку, используя алгоритм С++
        sort(arr_copy, arr_copy + SIZE);
        //cout << "C++ quick-sort time elapsed: " << static_cast<double>(clock() - start) / CLOCKS_PER_SEC << "\n";
        //cout << SIZE << " " << static_cast<double>(clock() - start) / CLOCKS_PER_SEC << "\n";
        SIZE += 2000;
    }

    return 0;
}