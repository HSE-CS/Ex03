#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "task1.h"

using namespace std;

int comp (const void* a, const void* b) 
{
    return (*(int*)a - *(int*)b);
}

int measure () 
{

    int arr[LARGE_SIZE];
    int arr_copy[LARGE_SIZE];
    // ������������ �� �������
    srand(time(0));
    // ���������� ��������� ������
    generate(arr, arr + LARGE_SIZE, rnd());
    copy(arr, arr + LARGE_SIZE, arr_copy);

    for (int i = 0; i < 50; ++i) {
        generate(arr, arr + LARGE_SIZE, rnd());
        copy(arr, arr + LARGE_SIZE, arr_copy);
        // �������� �����
        time_t start = clock();
        // ��������� ����������, ��������� ������� qsort
        qsort(arr, 10000 + 10000 * i, sizeof(int), comp);
        //cout << 10000+10000*i << " elements" << "\n";
        cout << 10000 + 10000 * i << ";";
        //cout << "C quick-sort time elapsed: " << static_cast<double>( clock() - start ) / CLOCKS_PER_SEC << "\n";
        cout << static_cast<double>(clock() - start) / CLOCKS_PER_SEC << ";";
        // ����� �������� �����
        start = clock();
        // ��������� ����������, ��������� �������� �++
        sort(arr_copy, arr_copy + 10000 + 10000 * i);
        //cout << "C++ quick-sort time elapsed: " << static_cast<double>( clock() - start ) / CLOCKS_PER_SEC << "\n" << "\n";
        cout << static_cast<double>(clock() - start) / CLOCKS_PER_SEC << "\n";
    }

}