#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "task1.h"


using namespace std;


int main()
{
	int arr[LARGE_SIZE];
	int arr_copy[LARGE_SIZE];
	int MY_ARRAY = 2000;
	// ������������ �� �������
	for (int i = 0; i < 50; i++)
	{
		cout << MY_ARRAY<<"\t";
		srand(time(nullptr));
		// ���������� ��������� ������
		generate(arr, arr + MY_ARRAY, rnd());
		copy(arr, arr + MY_ARRAY, arr_copy);
		// �������� �����
		time_t start = clock();
		// ��������� ����������, ��������� ������� qsort
		qsort(arr, MY_ARRAY, sizeof(int), comp);
		cout << static_cast<double>(clock() - start) / CLOCKS_PER_SEC<< "\t";
		// ����� �������� �����
		start = clock();
		// ��������� ����������, ��������� �������� �++
		sort(arr_copy, arr_copy + MY_ARRAY);
		cout << static_cast<double>(clock() - start) / CLOCKS_PER_SEC << "\t\t\t\n";
		MY_ARRAY += 2000;
	}
	return 0;
}