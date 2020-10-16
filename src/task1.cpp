#include <algorithm>
#include <iostream>
#include <cstdlib>
#include "task1.h"
#include <ctime>

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

void ComputeAndPrint(const int count) {
    int arr[LARGE_SIZE];
    int arr_copy[LARGE_SIZE];
    // Рандомизация по таймеру
    srand(time(nullptr));
    // генерируем случайные данные
    generate( arr, arr + count, rnd() );
    copy( arr, arr + count, arr_copy );
    // засекаем время
    time_t start = clock();
    // выполняем сортировку, используя функцию qsort
    qsort( arr, count, sizeof( int ), comp );
    cout << "count = " << count << " ";
    cout << "C : " << static_cast<double>( clock() - start ) / CLOCKS_PER_SEC << " ";
    // снова засекаем время
    start = clock();
    // выполняем сортировку, используя алгоритм С++
    sort( arr_copy, arr_copy + count );
    cout << "C++ : " << static_cast<double>( clock() - start ) / CLOCKS_PER_SEC << "\n";
}