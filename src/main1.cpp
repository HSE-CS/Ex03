#include "task1.h"

using namespace std;

int main() {
    int *arr = new int [LARGE_SIZE];
    int *arr_copy = new int [LARGE_SIZE];
    int size;
    // Рандомизация по таймеру
    for (int size = 10000;  size <= LARGE_SIZE; size += 10000)
    {
        srand(time(nullptr));
        // генерируем случайные данные
        generate( arr, arr + size, rnd() );
        copy( arr, arr + size, arr_copy );
        // засекаем время
        time_t start = clock();
        // выполняем сортировку, используя функцию qsort
        qsort( arr, size, sizeof( int ), comp );
        cout << "C quick-sort time elapsed: " << static_cast<double>( clock() - start ) / CLOCKS_PER_SEC << "\n";
        // снова засекаем время
        start = clock();
        // выполняем сортировку, используя алгоритм С++
        sort( arr_copy, arr_copy + size );
        cout << "C++ quick-sort time elapsed: " << static_cast<double>( clock() - start ) / CLOCKS_PER_SEC << "\n";
    }
    return 0;
}
