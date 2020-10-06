//
// Created by stanislav on 22/09/2020.
//

#include <fstream>
#include "task1.h"

int main() {
    int arr[LARGE_SIZE];
    int arr_copy[LARGE_SIZE];

    /*
     * Создаем файл для записи значений
     * C quick-sort и C++ quick-sort
     */
    ofstream cqc, cppqc;
    cqc.open("../data/cqc");
    cppqc.open("../data/cppqc");

    for (int i = 0; i < 50; ++i) {
        // Рандомизация по таймеру
        srand(time(nullptr));
        // генерируем случайные данные
        generate( arr, arr + LARGE_SIZE, rnd() );
        copy( arr, arr + LARGE_SIZE, arr_copy );
        // засекаем время
        time_t start = clock();
        // выполняем сортировку, используя функцию qsort
        qsort( arr, LARGE_SIZE, sizeof( int ), comp );
        //cout << "C quick-sort time elapsed: " << static_cast<double>( clock() - start ) / CLOCKS_PER_SEC << "\n";
        cqc << static_cast<double>( clock() - start ) / CLOCKS_PER_SEC << "\n";
        // снова засекаем время
        start = clock();
        // выполняем сортировку, используя алгоритм С++
        sort( arr_copy, arr_copy + LARGE_SIZE );
        //cout << "C++ quick-sort time elapsed: " << static_cast<double>( clock() - start ) / CLOCKS_PER_SEC << "\n";
        cppqc << static_cast<double>( clock() - start ) / CLOCKS_PER_SEC << "\n";
    }

    cqc.close();
    cppqc.close();

    return 0;
}

