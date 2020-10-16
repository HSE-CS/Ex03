#include "task1.h"


int main() {
    int arr[LARGE_SIZE];
    int arr_copy[LARGE_SIZE];
    for (int k = 5000; k <= LARGE_SIZE; k += 1000) {
        cout << k << "; ";
        // Рандомизация по таймеру
        srand(time(nullptr));
        // генерируем случайные данные
        generate(arr, arr + k, rnd());
        copy(arr, arr + k, arr_copy);
        // засекаем время
        time_t start = clock();
        // выполняем сортировку, используя функцию qsort
        qsort(arr, k, sizeof(int), comp);
        cout << static_cast<double>(clock() - start) / CLOCKS_PER_SEC << "; ";
        // снова засекаем время
        start = clock();
        // выполняем сортировку, используя алгоритм С++
        sort(arr_copy, arr_copy + k);
        cout << static_cast<double>(clock() - start) / CLOCKS_PER_SEC << "\n";
    }
    return 0;
}