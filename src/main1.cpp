#define _CRT_SECURE_NO_WARNINGS
#include "task1.h"
using namespace std;
int main() {
	int arr[LARGE_SIZE];
	int arr_copy[LARGE_SIZE];
	freopen("results.txt", "w", stdout);
	cout << "При одинаковых размерах массива функция C qsort работает быстрее, чем алгоритм C++ sort" << endl << "\n";
	cout << setw(15) << "Число элементов" << "|" << setw(15) << "C" << "|" << setw(15) << "C++" << "|" << endl;
	for (int i = 0; i < 100; i++) {
		// Рандомизация по таймеру
		srand(time(nullptr));
		// генерируем случайные данные
		generate(arr, arr + LARGE_SIZE, rnd());
		copy(arr, arr + LARGE_SIZE, arr_copy);
		// засекаем время
		time_t start = clock();
		cout << setw(15) << i * 1000 + 1000 << "|";
		qsort(arr, i * 1000 + 1000, sizeof(int), comp);
		cout << setw(15) << static_cast<double>(clock() - start) / CLOCKS_PER_SEC << "|";
		// снова засекаем время
		start = clock();
		// выполняем сортировку, используя алгоритм С++
		sort(arr_copy, arr_copy + i * 1000 + 1000);
		cout << setw(15) << static_cast<double>(clock() - start) / CLOCKS_PER_SEC << "|" << "\n";
	}
	fclose(stdout);
	return 0;
}



