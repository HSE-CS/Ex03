#include "task1.h"
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    int arr[LARGE_SIZE];
    int arr_copy[LARGE_SIZE];
    int n;
    int STEP = 1000;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        srand(time(nullptr));
        generate(arr, arr + STEP * i, rnd());
        copy(arr, arr + STEP * i, arr_copy);
        time_t start = clock();
        qsort(arr, STEP * i, sizeof(int), comp);
        cout << STEP * i << " " << static_cast<double>(clock() - start) / CLOCKS_PER_SEC << " "
            << static_cast<double>(clock() - start) / CLOCKS_PER_SEC << "\n";
        start = clock();
        sort(arr_copy, arr_copy + STEP * i);
        STEP += 20000;
    }

    return 0;
}