#include "task1.h"

int main() {
	int arr[LARGE_SIZE];
	int arr_copy[LARGE_SIZE];
	// Рандомизация по таймеру
	srand(time(nullptr));
	// генерируем случайные данные
	for (int i = 0; i < 50; i++) {
		generate(arr, arr + (i+1)*1000, rnd());
		copy(arr, arr + (i+1)*1000, arr_copy);
		// засекаем время
		time_t start = clock();
		cout<< "Size of array: " << (i + 1) * 1000<<"\n";
		// выполняем сортировку, используя функцию qsort
		qsort(arr, LARGE_SIZE, sizeof(int), comp);
		cout << "C quick-sort time elapsed: " << static_cast<double>(clock() - start) / CLOCKS_PER_SEC << "\n";
		// снова засекаем время
		start = clock();
		// выполняем сортировку, используя алгоритм С++
		sort(arr_copy, arr_copy + LARGE_SIZE);
		cout << "C++ quick-sort time elapsed: "<< static_cast<double>(clock() - start) / CLOCKS_PER_SEC << "\n\n";
	}
	return 0;
}