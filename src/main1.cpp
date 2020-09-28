#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "task1.h"

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
	srand(time(nullptr));	// Рандомизация по таймеру
	for (int i = 10000; i < LARGE_SIZE; i++) {
		generate(arr, arr + i, rnd());	// генерируем случайные данные
		copy(arr, arr + i, arr_copy);
		time_t start = clock();	// засекаем время
		qsort(arr, LARGE_SIZE, sizeof(int), comp);	// выполняем сортировку, используя функцию qsort
		cout << "C quick-sort time elapsed: " << static_cast<double>(clock() - start) / CLOCKS_PER_SEC << "\n";	// снова засекаем время
		start = clock();	// выполняем сортировку, используя алгоритм С++
		sort(arr_copy, arr_copy + LARGE_SIZE);
		cout << "C++ quick-sort time elapsed: " << static_cast<double>(clock() - start) / CLOCKS_PER_SEC << "\n";
	}
	return 0;
}