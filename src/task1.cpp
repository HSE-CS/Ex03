#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <task1.h>

using namespace std;

int comp( const void* a, const void* b ) {
    return ( *( int* )a - *( int* )b );
}

void measure(){
        int arr[LARGE_SIZE];
        int arr_copy[LARGE_SIZE];
        double CQSRes[50];
        double CPPQSRes[50];
        // Рандомизация по таймеру
        srand(time(nullptr));
        generate( arr, arr + LARGE_SIZE, rnd() );
        for (int i = 1; i <= 50; ++i) {
            int currSize = (LARGE_SIZE/50)*i;
            copy( arr, arr + currSize, arr_copy );
            // засекаем время
            time_t start = clock();
            // выполняем сортировку, используя функцию qsort
            qsort( arr_copy, currSize, sizeof( int ), comp );
            CQSRes[i-1] = static_cast<double>( clock() - start ) / CLOCKS_PER_SEC;
            copy( arr, arr + currSize, arr_copy );
            // снова засекаем время
            start = clock();
            // выполняем сортировку, используя алгоритм С++
            sort( arr_copy, arr_copy + currSize );
            CPPQSRes[i-1] = static_cast<double>( clock() - start ) / CLOCKS_PER_SEC;
        }
        cout << "Measurements each 2000 elements\n";
        for (int i = 0; i < 50; ++i) {
            cout << (i+1)*2000<<";";
            cout << CQSRes[i] << ";";
            cout << CPPQSRes[i]<<"\n" ;
        }

        }


