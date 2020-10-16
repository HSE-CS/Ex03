#include "task1.h"
using namespace std;

int main() {
    int arr[LARGE_SIZE];
    int arr_copy[LARGE_SIZE];
    for (int size = 2000; size <= LARGE_SIZE; size +=2000) {
        cout << size << " ";
        srand(time(nullptr));
        generate(arr, arr + size, rnd());
        copy(arr, arr + size, arr_copy);
        time_t start = clock();
        qsort(arr, size, sizeof(int), comp);
        cout << static_cast<double>(clock() - start) / CLOCKS_PER_SEC << " ";
        start = clock();
        sort(arr_copy, arr_copy + size);
        cout << static_cast<double>(clock() - start) / CLOCKS_PER_SEC << "\n";
    }
    return 0;
}