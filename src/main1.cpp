#include "task1.h"
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const size_t LARGE_SIZE =12000;

struct rnd {
    int operator()() {
        return rand() % LARGE_SIZE;
    }
};


int main() {
    int arr[LARGE_SIZE];
    int arr_copy[LARGE_SIZE];
    cout <<"Large_size "<< LARGE_SIZE<<endl;
    // Рандомизация по таймеру
    srand(time(nullptr));
    // генерируем случайные данные
    generate(arr, arr + LARGE_SIZE, rnd());
    copy(arr, arr + LARGE_SIZE, arr_copy);
    // засекаем время
    time_t start = clock();
    // выполняем сортировку, используя функцию qsort
    qsort(arr, LARGE_SIZE, sizeof(int), comp);
    cout << "C quick-sort time elapsed: " << static_cast<double>(clock() - start) / CLOCKS_PER_SEC << "\n";
    // снова засекаем время
    start = clock();
    // выполняем сортировку, используя алгоритм С++
    sort(arr_copy, arr_copy + LARGE_SIZE);
    cout << "C++ quick-sort time elapsed: " << static_cast<double>(clock() - start) / CLOCKS_PER_SEC << "\n";
    return 0;
}