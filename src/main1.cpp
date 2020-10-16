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

int main(int argc, char** argv) {
	size_t arr_size = LARGE_SIZE;

	if (argc > 1) {
		arr_size = atol(argv[1]);
	}
	cout << fixed;
	int* arr = new int[arr_size];
	int* arr_copy = new int[arr_size];
	// случайность по таймеру
	srand(time(nullptr));
	// создание случ данных
	generate(arr, arr + arr_size, rnd());
	copy(arr, arr + arr_size, arr_copy);
	// начало отсчета времени
	time_t start = clock();
	// сортировка с помощью qsort
	qsort(arr, arr_size, sizeof(int), comp);
	cout << static_cast<double>(clock() - start) / CLOCKS_PER_SEC << ",";
	// еще раз отсчет времени
	start = clock();
	// сортировка с использованием алгоритма —++
	sort(arr_copy, arr_copy + arr_size);
	cout << static_cast<double>(clock() - start) / CLOCKS_PER_SEC << ",";
	delete arr;
	delete arr_copy;
	return 0;
}