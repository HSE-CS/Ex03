#include "task1.h"

using namespace std;

int main() {
    unsigned int SIZE = 100;
        
    // Рандомизация по таймеру
    srand(time(nullptr));
    
    // генерируем случайные данные
    
    for (int i = 0; i < 50; i++) {
    int arr[SIZE];
    int arr_copy[SIZE];
        
    generate( arr, arr + SIZE, rnd() );
    copy( arr, arr + SIZE, arr_copy );
    cout << "SIZE: " << SIZE << "\n";
    // засекаем время
    time_t start = clock();
    // выполняем сортировку, используя функцию qsort
    qsort( arr, SIZE, sizeof( int ), comp );
    cout << "C quick-sort time elapsed: " << static_cast<double>( clock() - start ) / CLOCKS_PER_SEC << "\n";
    // снова засекаем время
    start = clock();
    // выполняем сортировку, используя алгоритм С++
    sort( arr_copy, arr_copy + SIZE );
    cout << "C++ quick-sort time elapsed: " << static_cast<double>( clock() - start ) / CLOCKS_PER_SEC << "\n";
    SIZE += SIZE/5;
    }
    
    return 0;
}
