#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include "task1.h"

using namespace std;

struct rnd {
    int operator()() {
        return rand() % LARGE_SIZE;
    }
};

int main() {
    int arr[LARGE_SIZE];
    int arr_copy[LARGE_SIZE];
    // Рандомизация по таймеру
    ofstream fout("large.txt");
    ofstream fout1("cdata.txt");
    ofstream fout2("cppdata.txt");

    for (int i = 51; i >1; i--) {
        srand(time(nullptr));
        // генерируем случайные данные
        generate(arr, arr + LARGE_SIZE/i, rnd());
        copy(arr, arr + LARGE_SIZE/i, arr_copy);
        fout << LARGE_SIZE/i << "\n";
        // засекаем время
        time_t start = clock();
        // выполняем сортировку, используя функцию qsort
        qsort(arr, LARGE_SIZE/i, sizeof(int), comp);
        //"C quick-sort time elapsed: "
        fout1 << static_cast<double>( clock() - start ) / CLOCKS_PER_SEC << "\n";
        // снова засекаем время
        start = clock();
        // выполняем сортировку, используя алгоритм С++
        sort(arr_copy, arr_copy + LARGE_SIZE/i);
        //C++ quick-sort time elapsed:
        fout2  << static_cast<double>( clock() - start ) / CLOCKS_PER_SEC << "\n";
    }
    return 0;
}