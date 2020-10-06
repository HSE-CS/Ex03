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
    int arr[LARGE_SIZE];
    int arr_copy[LARGE_SIZE];
    // Рандомизация по таймеру

    unsigned long int size_1 = 0;
    ofstream file;
    file.open("D:/C++/EX03/Ex03/data/results.txt");

    for(int i=0;i<50;i++){
        // генерируем случайные данные
        size_1=i*1917;
        srand(time(nullptr));
        generate(arr, arr + size_1, rnd());
        copy(arr, arr + size_1, arr_copy);
        // засекаем время
        time_t start = clock();
        // выполняем сортировку, используя функцию qsort
        qsort(arr, size_1, sizeof(int), comp);
        file << size_1 << " ";
        file << static_cast<double>( clock() - start ) / CLOCKS_PER_SEC << " ";

        // снова засекаем время
        start = clock();

        // выполняем сортировку, используя алгоритм С++
        sort(arr_copy, arr_copy + size_1);
        file << static_cast<double>( clock() - start ) / CLOCKS_PER_SEC << "\n ";

    }
    file.close();
    return 0;
}