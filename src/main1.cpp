#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "task1.h"

using namespace std;



int main() {
	int arr[LARGE_SIZE];
	int arr_copy[LARGE_SIZE];
		for (int step = 0; step < 100; step++) {
			// Рандомизация по таймеру
			srand(time(nullptr));
			// генерируем случайные данные
			generate(arr, arr + LARGE_SIZE, rnd());
			copy(arr, arr + LARGE_SIZE, arr_copy);
			// засекаем время
			time_t start = clock();
			cout << step * 1000 + 1000 << ";";
			// выполняем сортировку, используя функцию qsort
			qsort(arr, step * 1000 + 1000, sizeof(int), comp);
			cout << static_cast<double>(clock() - start) / CLOCKS_PER_SEC << ";";
			// снова засекаем время
			start = clock();
			// выполняем сортировку, используя алгоритм С++
			sort(arr_copy, arr_copy + step * 1000 + 1000);
			cout << static_cast<double>(clock() - start) / CLOCKS_PER_SEC << "\n";
	}
	return 0;
}

