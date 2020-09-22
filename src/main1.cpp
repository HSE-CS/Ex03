#include "task1.h"

using namespace std;


int main() {
    int arr[LARGE_SIZE];
    int arr_copy[LARGE_SIZE];
    // Рандомизация по таймеру
    srand(time(nullptr));
    // генерируем случайные данные
    size_t OUR_SIZE = 2000;
    for (int i = 0; i < 50; i++)
    {
        cout <<"size is "<< OUR_SIZE<<endl /* ";"*/;
        generate(arr, arr + OUR_SIZE, rnd());
        copy(arr, arr + OUR_SIZE, arr_copy);
        // засекаем время
        time_t start = clock();
        // выполняем сортировку, используя функцию qsort
        qsort(arr, OUR_SIZE, sizeof(int), comp);
        cout <<"C quick-sort time elapsed: " <<static_cast<double>(clock() - start) / CLOCKS_PER_SEC << "\n" /*";"*/;
        // снова засекаем время
        start = clock();
        // выполняем сортировку, используя алгоритм С++
        sort(arr_copy, arr_copy + OUR_SIZE);
        cout << "C++ quick-sort time elapsed: " << static_cast<double>(clock() - start) / CLOCKS_PER_SEC << "\n";
        OUR_SIZE += 2000;
    }
    
    return 0;
}