#include <algorithm>
#include <iostream>
#include <fstream>
#include "task1.h"
#include <ctime>

using namespace std;



int main() {
    ofstream fout;
    fout.open(R"(C:\Users\1314135\CLionProjects\Ex03\results.txt)");
    int arr[LARGE_SIZE];
    int arr_copy[LARGE_SIZE];
    for (int k = 50; k >= 0; k--) {
        srand(time(nullptr));
        generate(arr, arr + LARGE_SIZE, rnd());
        copy(arr, arr + LARGE_SIZE, arr_copy);
        time_t start = clock();
        qsort(arr, LARGE_SIZE - 1750 * k, sizeof(int), comp);
        fout << LARGE_SIZE - 1750 * k << "\t";
        fout << static_cast<double>( clock() - start ) / CLOCKS_PER_SEC << "\t";
        start = clock();
        sort(arr_copy, arr_copy + LARGE_SIZE - 1750 * k);
        fout << static_cast<double>( clock() - start ) / CLOCKS_PER_SEC << "\n";
    }
    fout.close();
    return 0;
}
