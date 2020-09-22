#include "task1.h"

using namespace std;


int main() {

    int arr[LARGE_SIZE];
    int arr_copy[LARGE_SIZE];

    int size = 0;

    for (int i = 0; i < 60; i++) {

        size += DELTA_SIZE;

        // Рандомизация по таймеру
        srand(time(nullptr));

        // генерируем случайные данные
        generate(arr, arr + size, rnd());
        copy(arr, arr + size, arr_copy);

        cout << "N = " << size << "\n";

        // засекаем время
        time_t start = clock();

        // выполняем сортировку, используя функцию qsort
        qsort(arr, size, sizeof(int), comp);

        cout << "C : " << static_cast<double>(clock() - start) / CLOCKS_PER_SEC << "\n";

        // снова засекаем время
        start = clock();

        // выполняем сортировку, используя алгоритм С++
        sort(arr_copy, arr_copy + size);

        cout << "C++ : " << static_cast<double>(clock() - start) / CLOCKS_PER_SEC << "\n";
    }
    
    return 0;
}