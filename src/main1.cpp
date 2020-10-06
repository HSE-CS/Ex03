//
// Created by sharg on 22.09.2020.
//

#include "task1.h"

int main() {
    int arr[LARGE_SIZE];
    int arr_copy[LARGE_SIZE];
    // Рандомизация по таймеру
    srand(time(nullptr));
    // генерируем случайные данные
    int iter=1;
    for(int i = 0;i < 50; i++) {
        iter+=3000;
        generate(arr, arr +iter, rnd());
        copy(arr, arr +iter, arr_copy);
        // засекаем время
        time_t start = clock();
        // выполняем сортировку, используя функцию qsort
        qsort(arr, iter, sizeof(int), comp);
        cout <<iter<<"\t"<< static_cast<double>( clock() - start ) / CLOCKS_PER_SEC << "\t";
        // снова засекаем время
        start = clock();
        // выполняем сортировку, используя алгоритм С++
        sort(arr_copy, arr_copy + iter);
        cout << static_cast<double>( clock() - start ) / CLOCKS_PER_SEC << "\n";
    }
    return 0;
}