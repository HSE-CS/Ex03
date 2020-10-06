#include "task1.h"

using namespace std;


int main() {

    int arr[LARGE_SIZE];
    int arr_copy[LARGE_SIZE];

    int size = 0;

    for (int i = 0; i < 60; i++) {

        size += DELTA_SIZE;

        // ������������ �� �������
        srand(time(nullptr));

        // ���������� ��������� ������
        generate(arr, arr + size, rnd());
        copy(arr, arr + size, arr_copy);

        cout << "N = " << size << "\n";

        // �������� �����
        time_t start = clock();

        // ��������� ����������, ��������� ������� qsort
        qsort(arr, size, sizeof(int), comp);

        cout << "C : " << static_cast<double>(clock() - start) / CLOCKS_PER_SEC << "\n";

        // ����� �������� �����
        start = clock();

        // ��������� ����������, ��������� �������� �++
        sort(arr_copy, arr_copy + size);

        cout << "C++ : " << static_cast<double>(clock() - start) / CLOCKS_PER_SEC << "\n";
    }
    
    return 0;
}