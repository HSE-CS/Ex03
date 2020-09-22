#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include "task1.h"

using namespace std;

const size_t LARGE_SIZE = 100000;

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
    file.open("D:\\results1.txt");
    // генерируем случайные данные
    for (int i = 0; i < 50; i++) {
        int LARGE_SIZE1 = 10000 + i * 1000;
        generate(arr, arr + LARGE_SIZE1, rnd());
        copy(arr, arr + LARGE_SIZE1, arr_copy);
        // засекаем время
        time_t start = clock();
        // выполняем сортировку, используя функцию qsort
        
        qsort(arr, LARGE_SIZE1, sizeof(int), comp);
        file << "C : "   << LARGE_SIZE1 << " ; ";
        file << static_cast<double>(clock() - start) / CLOCKS_PER_SEC << ";\n";
        // снова засекаем время
        start = clock();
        // выполняем сортировку, используя алгоритм С++
        sort(arr_copy, arr_copy + LARGE_SIZE1);
        file << "C++ : "  << LARGE_SIZE1 << " ;";
        file << static_cast<double>(clock() - start) / CLOCKS_PER_SEC << "\n";
    }
    return 0;
}
