#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include "task1.h"
using namespace std;


int main() {
    cout << "C quick-sort" << endl;
    for (int step = 0; step < 81; step++) {
        int* arr = new int[LARGE_SIZE + STEP * step];
        // Рандомизация по таймеру
        srand(time(nullptr));
        // генерируем случайные данные
        generate(arr, arr + LARGE_SIZE + STEP * step, rnd());\
        // засекаем время
        double start = clock();
        // выполняем сортировку, используя функцию qsort
        qsort(arr, LARGE_SIZE + STEP * step, sizeof(int), comp);
        double time = (clock() - start) / CLOCKS_PER_SEC;
        cout << setw(2) << step + 1 << '|' << setw(7) <<  LARGE_SIZE + STEP * step << '|' << time << "\n";
        delete []arr;
    }
    cout << "------------------------------" << "\n" << "C++ quick-sort" << endl;;
    for (int step = 0; step < 81; step++) {
        int* arr = new int[LARGE_SIZE + STEP * step];
        // Рандомизация по таймеру
        srand(time(nullptr));
        // генерируем случайные данные
        generate(arr, arr + LARGE_SIZE + STEP * step, rnd()); \
        // засекаем время
        double start = clock();
        // выполняем сортировку, используя алгоритм С++
        sort(arr, arr + LARGE_SIZE + STEP * step);
        double time = (clock() - start) / CLOCKS_PER_SEC;
        cout << step + 1 << '|' << LARGE_SIZE + STEP * step << '|' << time << "\n";
        delete[]arr;
    }
    return 0;
}