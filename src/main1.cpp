#include "task1.h"


int main() {
    const int TEST_AMOUNT = 100;
    int arr[LARGE_SIZE];
    short arr_copy[LARGE_SIZE];
    double tests[3][TEST_AMOUNT];
    // Рандомизация по таймеру
    srand(time(nullptr));

    ofstream fout("../data/results.txt");
    if (!fout) {cout << "ERROR! File is not opened!";return -1;}
    cout << "N\tC\tC++\n";
    for (int i = 1; i <= TEST_AMOUNT; ++i) {
        int arr_size = 1000*i;
        cout << arr_size << ';'; // << '\t';
        fout << arr_size << ';'; // << '\t';
        generate(arr, arr+arr_size, rnd());
        copy(arr, arr+arr_size, arr_copy);
        // C
        time_t start = clock();
        qsort(arr, arr_size, sizeof(int),comp);
        cout << static_cast<double>( clock() - start ) / CLOCKS_PER_SEC << ';'; // << '\t';
        fout <<  static_cast<double>( clock() - start ) / CLOCKS_PER_SEC << ';'; // << '\t';
        // C++
        start = clock();
        sort(arr_copy, arr_copy+arr_size);
        cout << static_cast<double>( clock() - start ) / CLOCKS_PER_SEC << ';';
        cout << '\n';
        fout <<  static_cast<double>( clock() - start ) / CLOCKS_PER_SEC << ';';
        fout << '\n';
    }
    fout.close();
    return 0;
}