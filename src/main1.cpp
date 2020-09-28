#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "task1.h"


using namespace std;

const size_t LARGE_SIZE = 200000;

struct rnd {
    int operator()() {
        return rand() % LARGE_SIZE;
    }
};

int main() {
    int arr[LARGE_SIZE];
    int arr_copy[LARGE_SIZE];
	
	
    // Рандомизация по таймеру
    srand(time(nullptr));
	
	
	cout << 'n' << '\t' << "C quick-sort time" << '\t' << "C++ quick-sort time" << endl;
	
	for (int i = 4000; i <= 200000; i += 4000) {
		
		
		cout << i << '\t';
		// генерируем случайные данные
		generate( arr, arr + i, rnd() );
		copy( arr, arr + i, arr_copy );
	
		// засекаем время
		time_t start = clock();
	
		// выполняем сортировку, используя функцию qsort
		qsort( arr, LARGE_SIZE, sizeof( int ), comp );
		cout << static_cast<double>( clock() - start ) / CLOCKS_PER_SEC << "\t";
   
		// снова засекаем время
		start = clock();
		// выполняем сортировку, используя алгоритм С++
		sort( arr_copy, arr_copy + LARGE_SIZE );
		cout << static_cast<double>( clock() - start ) / CLOCKS_PER_SEC << "\n";
	}
	
   
    return 0;
}