#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "task1.h"

using namespace std;

int main() {
	int arr[LARGE_SIZE];
	int arr_copy[LARGE_SIZE];
	// Рандомизация по таймеру
	srand(time(nullptr));
	// генерируем случайные данные
	for (int i = 0; i < 5; i++) {
		int LARGE_SIZE = rand() % 100000;
		cout << LARGE_SIZE << ' ';
		generate(arr, arr + LARGE_SIZE, rnd());
		copy(arr, arr + LARGE_SIZE, arr_copy);
		// засекаем время
		time_t start = clock();
		// выполняем сортировку, используя функцию qsort
		qsort(arr, LARGE_SIZE, sizeof(int), comp);
		cout << static_cast<double>(clock() - start) / CLOCKS_PER_SEC << ' ';
		// снова засекаем время
		start = clock();
		// выполняем сортировку, используя алгоритм С++
		sort(arr_copy, arr_copy + LARGE_SIZE);
		cout << static_cast<double>(clock() - start) / CLOCKS_PER_SEC << endl;
	}
	return 0;
}