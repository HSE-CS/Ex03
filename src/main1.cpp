#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <ctime>
#include "../include/task1.h"

using namespace std;

const size_t LARGE_SIZE = 100000;

struct rnd {
    int operator()() {
        return rand() % LARGE_SIZE;
    }
};

int main() {
    int arr[LARGE_SIZE];
    int arr_copy[LARGE_SIZE];
    srand(time(nullptr));

    ofstream output;
    output.open("../../data/result.txt"); 
    if (!output.is_open())
    {
        cout << "problem" << endl;
        
    }

    for (int i = 50; i > 0; i--)
    {
        size_t atmSize = LARGE_SIZE / i;
        generate(arr, arr + atmSize, rnd());
        copy(arr, arr + atmSize, arr_copy);
        time_t start = clock();
        qsort(arr, atmSize, sizeof(int), comp);
        time_t end = clock();
        cout << "#Size = " << atmSize << " # C quick-sort time elapsed: " << static_cast<double>(end - start) / CLOCKS_PER_SEC << "\n";
        output << atmSize << ';' << static_cast<double>(end - start) << ';';
        
        start = clock();
        sort(arr_copy, arr_copy + LARGE_SIZE/i);
        end = clock();
        cout << "#Size = " << atmSize << " # C++ quick-sort time elapsed: " << static_cast<double>(end - start) / CLOCKS_PER_SEC << "\n";
        output << static_cast<double>(end - start) << endl;
        

    }
    return 0;
} 