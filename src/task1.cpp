#include "task1.h"

int comp(const void* a, const void* b) {
	return (*(int*)a - *(int*)b);
}

void Proga(int sizeNew) {
	int arr[LARGE_SIZE];
	int arr_copy[LARGE_SIZE];
	// Рандомизация по таймеру
	srand(time(nullptr));
	// генерируем случайные данные
	generate(arr, arr + (sizeNew), rnd());
	copy(arr, arr + (sizeNew), arr_copy);
	// засекаем время
	time_t start = clock();
	// выполняем сортировку, используя функцию qsort
	qsort(arr, sizeNew, sizeof(int), comp);
	cout << "C quick-sort time elapsed: " << static_cast<double>(clock() - start) / CLOCKS_PER_SEC << "\n";
	// снова засекаем время
	start = clock();
	// выполняем сортировку, используя алгоритм С++
	sort(arr_copy, arr_copy + sizeNew);
	cout << "C++ quick-sort time elapsed: " << static_cast<double>(clock() - start) / CLOCKS_PER_SEC << "\n";
}
