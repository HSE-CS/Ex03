#include "task1.h"
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <math.h>


int main() 
{
    int arr[LARGE_SIZE];
    int arr_copy[LARGE_SIZE];
    int LARGE_SIZE1 = 0;
    for (int i = 0; i < 50; i++)
    {
        // ������������ �� �������
        srand(time(nullptr));
        // ���������� ��������� ������
        int num = pow(i + 1, 3);
        LARGE_SIZE1 = Random(LARGE_SIZE1, num);
        cout << "Size of array: " << LARGE_SIZE1 << "\n";
        generate(arr, arr + LARGE_SIZE1, rnd());
        copy(arr, arr + LARGE_SIZE1, arr_copy);
        // �������� �����
        time_t start = clock();
        // ��������� ����������, ��������� ������� qsort
        qsort(arr, LARGE_SIZE, sizeof(int), comp);
        cout << "C quick-sort time elapsed: " << static_cast<double>(clock() - start) / CLOCKS_PER_SEC << "\n";
        // ����� �������� �����
        start = clock();
        // ��������� ����������, ��������� �������� �++
        sort(arr_copy, arr_copy + LARGE_SIZE);
        cout << "C++ quick-sort time elapsed: " << static_cast<double>(clock() - start) / CLOCKS_PER_SEC << "\n";
        cout << "\n";
    }
    return 0;
}