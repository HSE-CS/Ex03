#include <algorithm>
#include <iostream>
#include <cstdlib>
#include "task1.h"
#include <ctime>

using namespace std;

const size_t LARGE_SIZE = 100000;

struct rnd {
	int operator()() {
		return rand() % LARGE_SIZE;
	}
};

int comp(const void* a, const void* b) {
	return (*(int*)a - *(int*)b);
}

void SortCompare(const int counter) {
	int arr[LARGE_SIZE];
	int arr_copy[LARGE_SIZE];
	// ������������ �� �������
	srand(time(nullptr));
	// ���������� ��������� ������
	generate(arr, arr + counter, rnd());
	copy(arr, arr + counter, arr_copy);
	// �������� �����
	time_t start = clock();
	// ��������� ����������, ��������� ������� qsort
	qsort(arr, counter, sizeof(int), comp);
	cout << "count = " << counter << " ";
	cout << "C : " << static_cast<double>(clock() - start) / CLOCKS_PER_SEC << " ";
	// ����� �������� �����
	start = clock();
	// ��������� ����������, ��������� �������� �++
	sort(arr_copy, arr_copy + counter);
	cout << "C++ : " << static_cast<double>(clock() - start) / CLOCKS_PER_SEC << "\n";
}