#include "task1.h"
using namespace std;

int main() {
	unsigned SIZE = 100000;
	for (int i = 0; i < 50; ++i) {
		int arr[LARGE_SIZE];
		int arr_copy[LARGE_SIZE];
		// ������������ �� �������
		srand(time(nullptr));
		// ���������� ��������� ������
		generate(arr, arr + SIZE, rnd());
		copy(arr, arr + SIZE, arr_copy);
		// �������� �����
		time_t start = clock();
		// ��������� ����������, ��������� ������� qsort
		qsort(arr, SIZE, sizeof(int), comp);
		cout << SIZE << " " << static_cast<double>(clock() - start) / CLOCKS_PER_SEC << " ";
		// ����� �������� �����
		start = clock();
		// ��������� ����������, ��������� �������� �++
		sort(arr_copy, arr_copy + SIZE);
		cout << static_cast<double>(clock() - start) / CLOCKS_PER_SEC << "\n";
		SIZE += 10000;
	}
	return 0;
}

