#include "task1.h"

using namespace std;

int main() {
    int arr[LARGE_SIZE];
    int arr_copy[LARGE_SIZE];

    int razmer = 0;
    // Рандомизация по таймеру
    ofstream filik;
    filik.open("D:/GIT/Ex03/data/result.txt");

    for (int i = 0; i < 50; i++)
    {
        //cout << i << "\n";
        srand(time(nullptr));
        // генерируем случайные данные
        razmer = i * 1800;
        generate(arr, arr + razmer, rnd());
        copy(arr, arr + razmer, arr_copy);
        // засекаем время
        time_t start = clock();
        // выполняем сортировку, используя функцию qsort
        qsort(arr, razmer, sizeof(int), comp);
        filik << razmer <<"\t";
        filik << static_cast<double>(clock() - start) / CLOCKS_PER_SEC << "\t";
        // снова засекаем время
        start = clock();
        // выполняем сортировку, используя алгоритм С++
        sort(arr_copy, arr_copy + razmer);
        filik << static_cast<double>(clock() - start) / CLOCKS_PER_SEC << "\n";
    }
    filik.close();
    return 0;
}
