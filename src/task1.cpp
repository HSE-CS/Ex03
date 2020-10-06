#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include "task1.h"

using namespace std;

int comp(const void* a, const void* b)
{
	return (*(int*)a - *(int*)b);
}
void check()
{
	ofstream fout("result.txt");
	fout.width(8);
	fout << "size";
	fout.width(10);
	fout << "c qsort";
	fout.width(10);
	fout << "c++ sort" << endl;
	int *arr=new int [LARGE_SIZE*50];
	int *arr_copy=new int[LARGE_SIZE*50];
	// Рандомизация по таймеру
	srand(time(0));
	for (int i = 0; i < 50; i++) 
	{
		generate(arr, arr + LARGE_SIZE, rnd());
		copy(arr, arr + LARGE_SIZE, arr_copy);
		// засекаем время
		time_t start = clock();
		// выполняем сортировку, используя функцию qsort
		//qsort(arr, 10000+10000 * i, sizeof(int), comp);
		qsort(arr,10000+ LARGE_SIZE * i, sizeof(int), comp);
		cout.width(8);
		fout.width(8);
		cout << 10000+LARGE_SIZE * i << ";";
		fout << 10000 + LARGE_SIZE * i << ";";
		cout.width(10);
		fout.width(10);
		cout << static_cast<double>(clock() - start) / CLOCKS_PER_SEC << ";";
		fout << static_cast<double>(clock() - start) / CLOCKS_PER_SEC << ";";
		// снова засекаем время
		start = clock();
		// выполняем сортировку, используя алгоритм С++
		cout.width(10);
		fout.width(10);
		//sort(arr_copy, arr_copy + 10000 + 10000 * i);
		sort(arr_copy, arr_copy +10000+ LARGE_SIZE * i);
		cout << static_cast<double>(clock() - start) / CLOCKS_PER_SEC << "\n";
		fout << static_cast<double>(clock() - start) / CLOCKS_PER_SEC << "\n";
	}
	delete arr;
	delete arr_copy;
	fout.close();
}