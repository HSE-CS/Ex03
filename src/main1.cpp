#include "task1.h"
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>

using namespace std;

const size_t LARGE_SIZE = 100000;

struct rnd {
    int operator()() {
        return rand() % LARGE_SIZE;
    }
};

int main() {
    int arr[LARGE_SIZE];
    int arr_copy[LARGE_SIZE];
    unsigned long int size_ = 0;
    ofstream file;
    file.open("/home/sid/Ex03/data/results.txt");
    for(int i = 1; i < 51; i++) {
        size_ = i*1960;
        srand(time(nullptr));
        // генерируем случайные данные
        generate(arr, arr + size_, rnd());
        copy(arr, arr + size_, arr_copy);
        // засекаем время
        time_t start = clock();
        // выполняем сортировку, используя функцию qsort
        qsort(arr, size_, sizeof(int), comp);
        file << size_ << " ";
        file << static_cast<double>( clock() - start ) / CLOCKS_PER_SEC << " ";
        // снова засекаем время
        start = clock();
        // выполняем сортировку, используя алгоритм С++
        sort(arr_copy, arr_copy + size_);
        file << static_cast<double>( clock() - start ) / CLOCKS_PER_SEC << "\n";
    }
    file.close();
    return 0;
}