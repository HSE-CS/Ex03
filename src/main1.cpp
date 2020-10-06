#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "task1.h"

int main() {
	int arr[LARGE_SIZE];
	int arr_copy[LARGE_SIZE];
	srand(time(nullptr));
	cout << "Размер\tC\tC++" << "\n";
	for (int i = 0; i < 50; i++) {
		int step = (rand() % ( LARGE_SIZE / 50  - 100) * (i + 1));
		generate(arr, arr + LARGE_SIZE - step, rnd());
		copy(arr, arr + LARGE_SIZE, arr_copy);
		time_t start = clock();
		qsort(arr, LARGE_SIZE - step, sizeof(int), comp);
		cout << (int)(LARGE_SIZE - step) << "\t" << static_cast<double>(clock() - start) / CLOCKS_PER_SEC;
		start = clock();
		sort(arr_copy, arr_copy + LARGE_SIZE - step);
		cout << " \t" << static_cast<double>(clock() - start) / CLOCKS_PER_SEC << "\n";
	}
	return 0;
}
