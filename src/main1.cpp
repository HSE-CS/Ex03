#include "task1.h"

using namespace std;

int main() {
    int arr[LARGE_SIZE];
    int arr_copy[LARGE_SIZE];
    // Рандомизация по таймеру
    srand(time(nullptr));
    ofstream fout;
    fout.open("/home/nikita/CLionProjects/Ex03/data/data.txt");
    for(int i = 0; i < 50; i++) {
        // генерируем случайные данные
        generate(arr, arr + i * 200, rnd());
        copy(arr, arr + i * 200, arr_copy);
        // засекаем время
        time_t start = clock();
        // выполняем сортировку, используя функцию qsort
        qsort(arr, LARGE_SIZE, sizeof(int), comp);
        fout << static_cast<double>( clock() - start ) / CLOCKS_PER_SEC << ";";
        // снова засекаем время
        start = clock();
        // выполняем сортировку, используя алгоритм С++
        sort(arr_copy, arr_copy + LARGE_SIZE);
        fout << static_cast<double>( clock() - start ) / CLOCKS_PER_SEC << ";";
        fout << i * 200 << "\n";
    }
    fout.close();
    return 0;
}