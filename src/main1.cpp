//
//  main1.cpp
//  cpp_exmp
//
//  Created by Сапожников Андрей Михайлович on 22.09.2020.
//  Copyright © 2020 Сапожников Андрей Михайлович. All rights reserved.
//

#include <stdio.h>
#include "task1.h"

#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <ctime>


using namespace std;

int main() {
    const float delta = 0.02;
    
    for (int i = 1; i < 51; i++){
        int arr[LARGE_SIZE];
        int arr_copy[LARGE_SIZE];
        int sort_size = LARGE_SIZE * i * delta;
        // Рандомизация по таймеру
        srand(time(nullptr));

        // генерируем случайные данные
        generate( arr, arr + LARGE_SIZE, rnd() );
        copy( arr, arr + LARGE_SIZE, arr_copy );
        cout << "Array size = " << sort_size << "\n";
        // засекаем время
        time_t start = clock();
        // выполняем сортировку, используя функцию qsort
        qsort( arr, sort_size, sizeof( int ), comp );
        cout << "C quick-sort time elapsed: " << static_cast<double>( clock() - start ) / CLOCKS_PER_SEC << "\n";
        // снова засекаем время
        start = clock();
        // выполняем сортировку, используя алгоритм С++
        sort( arr_copy, arr_copy + sort_size );
        cout << "C++ quick-sort time elapsed: " << static_cast<double>( clock() - start ) / CLOCKS_PER_SEC << "\n\n";
        
    }
    return 0;
}
