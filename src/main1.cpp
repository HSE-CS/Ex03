#include "task1.h"
#include <ctime>

using namespace std;

int main() {
    int arr[LARGE_SIZE];
    int arr_copy[LARGE_SIZE];
    // Рандомизация по таймеру
    for (int i = 0; i <= 50; i++) {
        srand(time(nullptr));
        // генерируем случайные данные
        generate(arr, arr + LARGE_SIZE, rnd());
        copy(arr, arr + LARGE_SIZE, arr_copy);

        double qTime = qsort_time(arr, 2000 * i);
        double sTime = sort_time(arr_copy, 2000 * i);
        //<< "\t" << sTime
        cout << "(" <<2000*i << ";" << sTime << ")" << endl;
    }
    return 0;
}
