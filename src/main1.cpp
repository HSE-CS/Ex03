#include "task1.h"

using namespace std;

int main() {
    int size = 1500;
    int arr[LARGE_SIZE];
    int arr_copy[LARGE_SIZE];

    // Рандомизация по таймеру
    srand(time(nullptr));
    // генерируем случайные данные
    generate(arr, arr + LARGE_SIZE, rnd());
    cout << "size\tC\t\tC++\n";
    for (int i = 0; i < 50; i++)
    {
        copy(arr, arr + size * i, arr_copy);
        // засекаем время
        time_t start = clock();
        // выполняем сортировку, используя функцию qsort
        qsort(arr, size * i, sizeof(int), comp);
        cout << size * i << '\t' <<  static_cast<double>(clock() - start) / CLOCKS_PER_SEC << '\t';
        // снова засекаем время
        start = clock();
        // выполняем сортировку, используя алгоритм С++
        sort(arr_copy, arr_copy + size * i);
        cout << static_cast<double>(clock() - start) / CLOCKS_PER_SEC << "\n";
    }
    return 0;
}