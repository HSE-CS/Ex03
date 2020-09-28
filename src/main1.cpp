#include "task1.h"

size_t LARGE_SIZE = 5000;
const int MAX_VALUE=500000;

struct rnd {
    int operator()() {
        return rand() % LARGE_SIZE;
    }
};

int main() {
    int arr[MAX_VALUE];
    int arr_copy[MAX_VALUE];
    // Рандомизация по таймеру
    srand(time(nullptr));
    // генерируем случайные данные
    cout << "[(0,0)";
    for (;LARGE_SIZE<=MAX_VALUE;LARGE_SIZE+=5000){
    generate( arr, arr + LARGE_SIZE, rnd() );
    copy( arr, arr + LARGE_SIZE, arr_copy );
    // засекаем время
    time_t start = clock();
    // выполняем сортировку, используя функцию qsort
    //qsort( arr, LARGE_SIZE, sizeof( int ), comp );
    //cout << ",("<<LARGE_SIZE<<"," << static_cast<double>( clock() - start ) / CLOCKS_PER_SEC<<")";
    // снова засекаем время
    //start = clock();
    // выполняем сортировку, используя алгоритм С++
    sort( arr_copy, arr_copy + LARGE_SIZE );
    cout << ",("<<LARGE_SIZE<<"," << static_cast<double>( clock() - start ) / CLOCKS_PER_SEC<<")";
    }
    cout << "]";
    return 0;
}