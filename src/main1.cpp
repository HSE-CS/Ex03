#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "task1.h"

//const size_t arr_size = 5;


using namespace std;


int main()
{
	int arr[LARGE_SIZE];
	int arr_copy[LARGE_SIZE];
	int arr_size = 1000;
	// Рандомизация по таймеру
	for (int i = 0; i < 50; i++)
	{
		cout << arr_size << ";  ";
	//	arr_size += 5;
		srand(time(nullptr));
		// генерируем случайные данные
		generate(arr, arr + arr_size, rnd());
		copy(arr, arr + arr_size, arr_copy);
		// засекаем время
		time_t start = clock();
		// выполняем сортировку, используя функцию qsort
		qsort(arr, arr_size, sizeof(int), comp);
		cout << static_cast<double>(clock() - start) / CLOCKS_PER_SEC<< ";" << "\t";
		// снова засекаем время
		start = clock();
		// выполняем сортировку, используя алгоритм С++
		sort(arr_copy, arr_copy + arr_size);
		cout << static_cast<double>(clock() - start) / CLOCKS_PER_SEC << "\t\t\n";
		arr_size += 2000;
	}
	return 0;
}