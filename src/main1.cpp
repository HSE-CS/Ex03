//
// Created by kdash on 28.09.2020.
//
#include "task1.h"
int main() {
    int* arr = new int[LARGE_SIZE];
    int* arr_copy = new int[LARGE_SIZE];
    unsigned int step[50];
    double time_c[50], time_cpp[50];
    unsigned int b=0;

    srand(time(nullptr));

    for(int i=0;i<50;i++){
        step[i]=b;
        generate(arr, arr + b, rnd());
        copy(arr, arr + b, arr_copy);

        time_t start = clock();

        qsort(arr, b, sizeof(int), comp);

        time_c[i] = static_cast<double>(clock() - start) / CLOCKS_PER_SEC;
        start = clock();

        sort(arr_copy, arr_copy + b);
        time_cpp[i]=static_cast<double>(clock() - start) / CLOCKS_PER_SEC;

        b+=3000;
    }

    cout << "n\tC\tC++" << endl;
    for(int i=0;i<50;i++){
        cout << step[i] << "\t" << time_c[i] << "\t" << time_cpp[i] << endl;
    }

    return 0;
}