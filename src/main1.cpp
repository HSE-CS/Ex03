#include <algorithm>
#include <fstream>
#include <ctime>
#include "task1.h"

using namespace std;

int main() {
	ofstream fout;
	fout.open(R"(C:\Users\user\source\repos\Ex03\Ex03\results.txt)");
	int arr[LARGE_SIZE];
	int arr_copy[LARGE_SIZE];
	// ������������ �� �������
	srand(time(nullptr));
	// ���������� ��������� ������
	for (int i = 0; i < 50; i++)
	{
		generate(arr, arr + 500 + (i + 1) * 500, rnd());
		copy(arr, arr + 500 + (i + 1) * 500, arr_copy);
		fout << 500 + (i + 1) * 500 << "\t";
		// �������� �����
		time_t start = clock();
		// ��������� ����������, ��������� ������� qsort
		qsort(arr, 500 + (i + 1) * 500, sizeof(int), comp);
		fout << static_cast<double>(clock() - start) / CLOCKS_PER_SEC << "\t";
		// ����� �������� �����
		start = clock();
		// ��������� ����������, ��������� �������� �++
		sort(arr_copy, arr_copy + 500 + (i + 1) * 500);
		fout << static_cast<double>(clock() - start) / CLOCKS_PER_SEC << "\n";
	}
	fout.close();
	return 0;
}
