#include <iostream>
#include "task1.h"
using namespace std;


int main() {
    int arr[LARGE_SIZE];
    int arr_copy[LARGE_SIZE];
    // Рандомизация по таймеру
    srand(time(nullptr));
    // int size = 10;
    // генерируем случайные данные
    ofstream outf("results.txt");
    for (int size = 3000; size < 100000; size += 1000) {
        generate(arr, arr + size, rnd());
        copy(arr, arr + size, arr_copy);
        // засекаем время
        time_t start = clock();
        // выполняем сортировку, используя функцию qsort
        qsort(arr, size, sizeof(int), comp);
        double qsort_time = static_cast<double>( clock() - start ) / CLOCKS_PER_SEC;
        // снова засекаем время
        start = clock();
        // выполняем сортировку, используя алгоритм С++
        sort(arr_copy, arr_copy + size);
        double sort_time = static_cast<double>( clock() - start ) / CLOCKS_PER_SEC;
        outf << size << ';' << qsort_time << ';' << sort_time << endl;
    }
    return 0;
}
