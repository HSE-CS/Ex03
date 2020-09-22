#include "task1.h"

int main() {
	int arr[LARGE_SIZE];
	int arr_copy[LARGE_SIZE];
	// ������������ �� �������
	srand(time(nullptr));
	// ���������� ��������� ������
	for (int i = 0; i < 50; i++) {
		generate(arr, arr + (i+1)*1000, rnd());
		copy(arr, arr + (i+1)*1000, arr_copy);
		// �������� �����
		time_t start = clock();
		cout<< "Size of array: " << (i + 1) * 1000<<"\n";
		// ��������� ����������, ��������� ������� qsort
		qsort(arr, LARGE_SIZE, sizeof(int), comp);
		cout << "C quick-sort time elapsed: " << static_cast<double>(clock() - start) / CLOCKS_PER_SEC << "\n";
		// ����� �������� �����
		start = clock();
		// ��������� ����������, ��������� �������� �++
		sort(arr_copy, arr_copy + LARGE_SIZE);
		cout << "C++ quick-sort time elapsed: "<< static_cast<double>(clock() - start) / CLOCKS_PER_SEC << "\n\n";
	}
	return 0;
}