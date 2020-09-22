//
// Created by toliman on 22.09.2020.
//

#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

#include "task1.h"

using namespace std;


int main() {

    cout.precision(16);

    int tests(100);

    double base = 1.096478196143185;
    double cur = 1000.0;
    vector<int> sizes(tests, 0);
    int cnt = 0;
    for (auto &x: sizes) {
        x = (int) cur;
        cur *= base;
        cout << (int) cur << '>' << cnt << ' ';
        cnt++;
    }

    for (int i = 0; i < 20; ++i) {
        int arr[sizes[i]];
        int arr_copy[sizes[i]];
        // Рандомизация по таймеру
        srand(time(nullptr));
        // генерируем случайные данные
        generate(arr, arr + sizes[i], rnd());
        copy(arr, arr + sizes[i], arr_copy);
        // засекаем время
        time_t start = clock();
        // выполняем сортировку, используя функцию qsort
        qsort(arr, sizes[i], sizeof(int), comp);
        cout << i << ".0;";
        cout << static_cast<double>( clock() - start ) / CLOCKS_PER_SEC << ";";
        // снова засекаем время
        start = clock();
        // выполняем сортировку, используя алгоритм С++
        sort(arr_copy, arr_copy + sizes[i]);
        cout << static_cast<double>( clock() - start ) / CLOCKS_PER_SEC << "\n";
    }

    return 0;
}
