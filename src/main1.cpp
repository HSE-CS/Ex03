#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "task1.h"


int main() {
	int arr[LARGE_SIZE];
	int arr_copy[LARGE_SIZE];
	// ������������ �� �������
	srand(time(nullptr));
	cout << "SIZE C C++\n";
	for (int i = 0;i < 50;i++)
	{

		int step = 1900*i;
		// ���������� ��������� ������
		generate(arr, arr + LARGE_SIZE-step, rnd());
		copy(arr, arr + LARGE_SIZE-step, arr_copy);
		// �������� �����
		time_t start = clock();
		// ��������� ����������, ��������� ������� qsort
		qsort(arr, LARGE_SIZE-step, sizeof(int), comp);
		cout << (int)(LARGE_SIZE - step) <<" "<< static_cast<double>(clock() - start) / CLOCKS_PER_SEC<< " ";
		// ����� �������� �����
		start = clock();
		// ��������� ����������, ��������� �������� �++
		sort(arr_copy, arr_copy + LARGE_SIZE-step);
		cout << static_cast<double>(clock() - start) / CLOCKS_PER_SEC << "\n";
	}
	return 0;
}