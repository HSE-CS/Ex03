#include <stdio.h>
#include <iostream>
#include "task1.h"
using namespace std;

int main()
{
    int arr[LARGE_SIZE];
    int arr_copy[LARGE_SIZE];
    // Рандомизация по таймеру
    srand(time(nullptr));
    // генерируем случайные данные

    for(int i = 0;i < 50; i++) {

        generate(arr, arr + (i + 1)*6000, rnd());
        copy(arr, arr +  (i + 1)*6000, arr_copy);
        // засекаем время
        time_t start = clock();
        // выполняем сортировку, используя функцию qsort
        qsort(arr,  (i + 1)*6000, sizeof(int), comp);
        cout << "C quick-sort time for "<<  (i + 1)*6000 <<" elements elapsed: "<<static_cast<double>( clock() - start ) / CLOCKS_PER_SEC << "\n";
        // снова засекаем время
        start = clock();
        // выполняем сортировку, используя алгоритм С++
        sort(arr_copy, arr_copy +  (i + 1)*6000);
        cout << "C++ quick-sort time for "<<  (i + 1)*6000 <<" elements elapsed: " << static_cast<double>( clock() - start ) / CLOCKS_PER_SEC <<"\n";
    }
    return 0;
}
