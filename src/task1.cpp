#include "task1.h"

int comp(const void* a, const void* b) {
	return (*(int*)a - *(int*)b);
}

void Proga(int sizeNew) {
	int arr[LARGE_SIZE];
	int arr_copy[LARGE_SIZE];
	// ������������ �� �������
	srand(time(nullptr));
	// ���������� ��������� ������
	generate(arr, arr + (sizeNew), rnd());
	copy(arr, arr + (sizeNew), arr_copy);
	// �������� �����
	time_t start = clock();
	// ��������� ����������, ��������� ������� qsort
	qsort(arr, sizeNew, sizeof(int), comp);
	cout << "C quick-sort time elapsed: " << static_cast<double>(clock() - start) / CLOCKS_PER_SEC << "\n";
	// ����� �������� �����
	start = clock();
	// ��������� ����������, ��������� �������� �++
	sort(arr_copy, arr_copy + sizeNew);
	cout << "C++ quick-sort time elapsed: " << static_cast<double>(clock() - start) / CLOCKS_PER_SEC << "\n";
}
