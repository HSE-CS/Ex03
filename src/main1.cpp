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
	srand(time(nullptr));	// ������������ �� �������
	for (int i = 10000; i < LARGE_SIZE; i++) {
		generate(arr, arr + i, rnd());	// ���������� ��������� ������
		copy(arr, arr + i, arr_copy);
		time_t start = clock();	// �������� �����
		qsort(arr, LARGE_SIZE, sizeof(int), comp);	// ��������� ����������, ��������� ������� qsort
		cout << "C quick-sort time elapsed: " << static_cast<double>(clock() - start) / CLOCKS_PER_SEC << "\n";	// ����� �������� �����
		start = clock();	// ��������� ����������, ��������� �������� �++
		sort(arr_copy, arr_copy + LARGE_SIZE);
		cout << "C++ quick-sort time elapsed: " << static_cast<double>(clock() - start) / CLOCKS_PER_SEC << "\n";
	}
	return 0;
}