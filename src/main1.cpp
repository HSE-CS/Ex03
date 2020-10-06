#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "task1.h"


using namespace std;

//const size_t LARGE_SIZE = 100000;


int main() {
    int* arr;
    int* arr_copy;
    arr = (int*)malloc(sizeof(int) * LARGE_SIZE);
    arr_copy = (int*)malloc(sizeof(int) * LARGE_SIZE);
    //int arr[LARGE_SIZE];
    //int arr_copy[LARGE_SIZE];
    // ������������ �� �������
    srand(time(nullptr));
    // ���������� ��������� ������
    generate(arr, arr + LARGE_SIZE, rnd());
    copy(arr, arr + LARGE_SIZE, arr_copy);
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
    return 0;
}