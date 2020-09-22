#include <limits>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "task1.h"

using namespace std;

int main() {
    int arr[LARGE_SIZE];
    int arr_copy[LARGE_SIZE];

    for(int i = LARGE_SIZE; i > 0; i-=2000){
        int real_size = LARGE_SIZE - i;
        // Рандомизация по таймеру
        srand(time(nullptr));
        // генерируем случайные данные
        generate( arr, arr + real_size, rnd() );
        copy( arr, arr + real_size, arr_copy );
        // засекаем время
        time_t start = clock();
        // выполняем сортировку, используя функцию qsort
        qsort( arr, real_size, sizeof( int ), comp );
        double time1 = static_cast<double>( clock() - start ) / CLOCKS_PER_SEC;
        // cout << "C quick-sort time elapsed: " << static_cast<double>( clock() - start ) / CLOCKS_PER_SEC << "\n";
        // снова засекаем время
        start = clock();
        // выполняем сортировку, используя алгоритм С++
        sort( arr_copy, arr_copy + real_size );
        // cout << "C++ quick-sort time elapsed: " << static_cast<double>( clock() - start ) / CLOCKS_PER_SEC << "\n";
        double time2 = static_cast<double>( clock() - start ) / CLOCKS_PER_SEC ;
        cout.precision(5);
        cout << real_size << " " << fixed << time1 << " " << fixed << time2 << endl;

    }
    return 0;
}
