#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "task1.h"
#include <math.h>

using namespace std;

int main() 
{
	int arr[LARGE_SIZE];
	int arr_copy[LARGE_SIZE];
	int counter = 0;
	size_t currentSize = 1000;
	// ������������ �� �������
	srand(time(nullptr));
	while (counter < 50) {
		// ���������� ��������� ������
		generate(arr, arr + currentSize, rnd());
		copy(arr, arr + currentSize, arr_copy);
		cout << currentSize << "	";
		// �������� �����
		time_t start = clock();
		// ��������� ����������, ��������� ������� qsort
		qsort(arr, LARGE_SIZE, sizeof(int), comp);
		cout << static_cast<double>(clock() - start) / CLOCKS_PER_SEC << "	";
		// ����� �������� �����
		start = clock();
		// ��������� ����������, ��������� �������� �++
		sort(arr_copy, arr_copy + LARGE_SIZE);
		cout << static_cast<double>(clock() - start) / CLOCKS_PER_SEC << "\n";
		counter++;
		currentSize += 2000;
	}
	return 0;
}