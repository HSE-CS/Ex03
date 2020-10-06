#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "task1.h"

using namespace std;

const size_t LARGE_SIZE = 500000;

struct rnd {
    int operator()() {
        return rand() % LARGE_SIZE;
    }
};

int main() {
    int* arr = new int[LARGE_SIZE];
    int* arr_copy = new int[LARGE_SIZE];
    // ������������ �� �������
    for (int k = 0; k <= LARGE_SIZE; k = k + 5000) {
        cout << k << "; ";
        srand(time(nullptr));
        // ���������� ��������� ������
        generate(arr, arr + k, rnd());
        copy(arr, arr + k, arr_copy);
        // �������� �����
        time_t start = clock();
        // ��������� ����������, ��������� ������� qsort
        qsort(arr, k, sizeof(int), comp);
        cout << static_cast<double>(clock() - start) / CLOCKS_PER_SEC << "; ";
        // ����� �������� �����
        start = clock();
        // ��������� ����������, ��������� �������� �++
        sort(arr_copy, arr_copy + k);
        cout << static_cast<double>(clock() - start) / CLOCKS_PER_SEC << "\n";
    }
    return 0;
}