#include <algorithm>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <ctime>


using namespace std;

const size_t LARGE_SIZE = 1000000;

struct rnd {
    int operator()() {
        return rand() % LARGE_SIZE;
    }
};

int comp( const void* a, const void* b ) {
    return ( *( int* )a - *( int* )b );
}

int main() {
    ofstream file;
    int arr[LARGE_SIZE];
    int arr_copy[LARGE_SIZE];
    // Рандомизация по таймеру
    srand(time(nullptr));
    file.open("/Users/aleksandrgrachev/CLionProjects/Ex03/data/results.txt");
    for (int i = 0; i < 50; i++){
        // генерируем случайные данные
        generate( arr, arr + (i * 1000), rnd() );
        copy( arr, arr + (i * 1000), arr_copy );
        // засекаем время
        time_t start = clock();
        // выполняем сортировку, используя функцию qsort
        qsort( arr, (i * 1000), sizeof( int ), comp );
        file << static_cast<double>( clock() - start ) / CLOCKS_PER_SEC << "\n";
        // снова засекаем время
        start = clock();
        // выполняем сортировку, используя алгоритм С++
        sort( arr_copy, arr_copy + (i * 1000) );
        file << static_cast<double>( clock() - start ) / CLOCKS_PER_SEC << "\n";
    }
    file.close();
    return 0;
}
