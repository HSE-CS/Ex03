#include <algorithm>
#include <ctime>
#include <fstream>
#include "task1.h"

int main() {
    int sort_size = 100;
    int *arr;
    int *arr_copy;

    ofstream file;
    file.open("../data/results.txt");

    for(int i = 0; i < 50; i++) {
        if (i % 10 == 0) sort_size *= 10;
        arr = new int[sort_size];
        arr_copy = new int[sort_size];
        // rand
        srand(time(nullptr));
        generate( arr, arr + sort_size, rnd() );
        copy( arr, arr + sort_size, arr_copy );
        // C
        time_t start = clock();
        qsort( arr, sort_size, sizeof( int ), comp );
        file << i + 1 << ")" << sort_size << " C: " << static_cast<double>( clock() - start ) / CLOCKS_PER_SEC << "\t";
        // C++
        start = clock();
        sort( arr_copy, arr_copy + sort_size );
        file << "C++: " << static_cast<double>( clock() - start ) / CLOCKS_PER_SEC << "\n";
    }

    delete [] arr;
    delete [] arr_copy;
    file.close();

    return 0;
}