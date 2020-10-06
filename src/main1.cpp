//
// Created by stoja on 22.09.2020.
//

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

int comp( const void* a, const void* b ) {
    return ( *( int* )a - *( int* )b );
}

int main() {
    ofstream file;
    int arr[LARGE_SIZE];
    int arr_copy[LARGE_SIZE];
    // Рандомизация по таймеру
    srand(time(nullptr));
    file.open("C://Users/stoja/CLionProjects/Ex03/data/results.txt");
    for(int i=0; i<50; i++) {
        // генерируем случайные данные
        generate(arr, arr + i*100, rnd());
        copy(arr, arr + i*100, arr_copy);
        file << i*100 << "; ";
        // засекаем время
        time_t start = clock();
        // выполняем сортировку, используя функцию qsort
        qsort(arr, LARGE_SIZE, sizeof(int), comp);
        file <<  static_cast<double>( clock() - start ) / CLOCKS_PER_SEC << "; ";
        //cout << "C quick-sort time elapsed: " << static_cast<double>( clock() - start ) / CLOCKS_PER_SEC << "\n";
        // снова засекаем время
        start = clock();
        // выполняем сортировку, используя алгоритм С++
        sort(arr_copy, arr_copy + LARGE_SIZE);
        file <<  static_cast<double>( clock() - start ) / CLOCKS_PER_SEC << "\n";
        //cout << "C++ quick-sort time elapsed: " << static_cast<double>( clock() - start ) / CLOCKS_PER_SEC << "\n";
    }
    return 0;
}