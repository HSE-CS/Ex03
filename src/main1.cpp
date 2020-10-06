#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include "task1.h"

using namespace std;

const size_t LARGE_SIZE = 1000000;

struct rnd {
    int operator()() {
        return rand() % LARGE_SIZE;
    }
};

int main() {
    ofstream file;
    int arr[LARGE_SIZE];
    int arr_copy[LARGE_SIZE];
    // Рандомизация по таймеру
    srand(time(nullptr));
    file.open("/Users/igy/Desktop/Ex03/data/results.txt");
    // генерируем случайные данные
    for(int i=0; i<50; i++) {
        generate(arr, arr + i*222, rnd());
        copy(arr, arr + i*222, arr_copy);
        file << i*222 << "; ";
        // засекаем время
        time_t start = clock();
        // выполняем сортировку, используя функцию qsort
        qsort(arr, LARGE_SIZE, sizeof(int), comp);
        file <<  static_cast<double>( clock() - start ) / CLOCKS_PER_SEC << "; ";
        // снова засекаем время
        start = clock();
        // выполняем сортировку, используя алгоритм С++
        sort(arr_copy, arr_copy + LARGE_SIZE);
        file <<  static_cast<double>( clock() - start ) / CLOCKS_PER_SEC << "\n";
    }
    file.close();
    return 0;
}
