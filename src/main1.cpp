
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include "../include/task1.h"

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
    int arr[LARGE_SIZE];
    int arr_copy[LARGE_SIZE];
    ofstream out("results.txt");
    for (int i = 50; i > 0; i--)
    {
        srand(time(nullptr));
        // генерируем случайные данные
        std::generate( arr, arr + LARGE_SIZE, rnd() );
        std::copy( arr, arr + LARGE_SIZE, arr_copy );
        // засекаем время
        time_t start = clock();
        // выполняем сортировку, используя функцию qsort
        qsort( arr, LARGE_SIZE - (1500 * i), sizeof( int ), comp );
        out << LARGE_SIZE - (1500 * i) << "; " << static_cast<double>( clock() - start ) / CLOCKS_PER_SEC << "; ";
        // снова засекаем время
        start = clock();
        // выполняем сортировку, используя алгоритм С++
        std::sort( arr_copy, arr_copy + LARGE_SIZE - (1500 * i) );
        out << static_cast<double>( clock() - start ) / CLOCKS_PER_SEC << "\n";
    }
    return 0;
}

