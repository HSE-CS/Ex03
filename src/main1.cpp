#include "../include/task1.h"
using namespace std;

int main() {
    unsigned SIZE = 100000;
    int n = 50;
    for (int i = 0; i < n; ++i) {
        int arr[LARGE_SIZE];
        int arr_copy[LARGE_SIZE];
        // Рандомизация по таймеру
        srand(time(nullptr));
        // генерируем случайные данные
        generate(arr, arr + SIZE, rnd());
        copy(arr, arr + SIZE, arr_copy);
        // засекаем время
        time_t start = clock();
        // выполняем сортировку, используя функцию qsort
        qsort(arr, SIZE, sizeof(int), comp);
        cout << SIZE << " " << static_cast<double>( clock() - start ) / CLOCKS_PER_SEC << " ";
        // снова засекаем время
        start = clock();
        // выполняем сортировку, используя алгоритм С++
        sort(arr_copy, arr_copy + SIZE);
        cout << static_cast<double>( clock() - start ) / CLOCKS_PER_SEC << "\n";
        SIZE += 10000;
    }
    return 0;
}

