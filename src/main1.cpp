#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "task1.h"

using namespace std;

int main() {
    int arr[LARGE_SIZE];
    int arr_copy[LARGE_SIZE];

    for (int i = 0; i < 50; i++) {
        // ������������ �� �������
        srand(time(nullptr));
        // ���������� ��������� ������
        int LARGE_SIZE1 = 10000 + i * 1500;
        //cout << "Array size " << LARGE_SIZE1 << "\n";
        generate(arr, arr + LARGE_SIZE1, rnd());
        copy(arr, arr + LARGE_SIZE1, arr_copy);
        // �������� �����
        time_t start = clock();
        // ��������� ����������, ��������� ������� qsort
        qsort(arr, LARGE_SIZE1, sizeof(int), comp);
        cout << LARGE_SIZE1 << ";" << static_cast<double>(clock() - start) / CLOCKS_PER_SEC << "\t";
        // ����� �������� �����
        start = clock();
        // ��������� ����������, ��������� �������� �++
        sort(arr_copy, arr_copy + LARGE_SIZE1);
        cout << LARGE_SIZE1 << ";" << static_cast<double>(clock() - start) / CLOCKS_PER_SEC << "\n";
    }
    return 0;
}