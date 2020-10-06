#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>

#include "task1.h"

using namespace std;

const size_t LARGE_SIZE = 100000;

struct rnd {
    int operator()() {
        return rand() % LARGE_SIZE;
    }
};



int main() {
    int l = 1234;
    int arr[LARGE_SIZE];
    int arr_copy[LARGE_SIZE];
    // Рандомизация по таймеру
    srand(time(nullptr));
    // генерируем случайные данные
    generate(arr, arr + LARGE_SIZE, rnd());
    ofstream fout;
    fout.open("C:\\Users\\nikit\\source\\repos\\ex03\\ex03\\results.txt");
    for (int i = 0; i < 50; i++){
        copy(arr, arr + l*i, arr_copy);
        // засекаем время
        time_t start = clock();
        // выполняем сортировку, используя функцию qsort
        qsort(arr, l*i, sizeof(int), comp);
        fout << l*i << " " << static_cast<double>(clock() - start) / CLOCKS_PER_SEC << " ";
        // снова засекаем время
        start = clock();
        // выполняем сортировку, используя алгоритм С++
        sort(arr_copy, arr_copy + l*i);
        fout << static_cast<double>(clock() - start) / CLOCKS_PER_SEC << "\n";
    }
    fout << "\nqsort в С работает быстрее чем в С++\nОба графика линейны";
    fout.close();
    return 0;
}