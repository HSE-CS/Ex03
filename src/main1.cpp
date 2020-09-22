#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "task1.h"
#include <math.h>

using namespace std;

int main() 
{
	int arr[LARGE_SIZE];
	int arr_copy[LARGE_SIZE];
	int counter = 0;
	size_t currentSize = 1000;
	// Рандомизация по таймеру
	srand(time(nullptr));
	while (counter < 50) {
		// генерируем случайные данные
		generate(arr, arr + currentSize, rnd());
		copy(arr, arr + currentSize, arr_copy);
		cout << currentSize << "	";
		// засекаем время
		time_t start = clock();
		// выполняем сортировку, используя функцию qsort
		qsort(arr, LARGE_SIZE, sizeof(int), comp);
		cout << static_cast<double>(clock() - start) / CLOCKS_PER_SEC << "	";
		// снова засекаем время
		start = clock();
		// выполняем сортировку, используя алгоритм С++
		sort(arr_copy, arr_copy + LARGE_SIZE);
		cout << static_cast<double>(clock() - start) / CLOCKS_PER_SEC << "\n";
		counter++;
		currentSize += 2000;
	}
	return 0;
}