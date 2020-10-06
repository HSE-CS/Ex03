#include "task1.h"

using namespace std;

int main() {
    int size = 1500;
    int arr[LARGE_SIZE];
    int arr_copy[LARGE_SIZE];

    // ������������ �� �������
    srand(time(nullptr));
    // ���������� ��������� ������
    generate(arr, arr + LARGE_SIZE, rnd());
    cout << "size\tC\t\tC++\n";
    for (int i = 0; i < 50; i++)
    {
        copy(arr, arr + size * i, arr_copy);
        // �������� �����
        time_t start = clock();
        // ��������� ����������, ��������� ������� qsort
        qsort(arr, size * i, sizeof(int), comp);
        cout << size * i << '\t' <<  static_cast<double>(clock() - start) / CLOCKS_PER_SEC << '\t';
        // ����� �������� �����
        start = clock();
        // ��������� ����������, ��������� �������� �++
        sort(arr_copy, arr_copy + size * i);
        cout << static_cast<double>(clock() - start) / CLOCKS_PER_SEC << "\n";
    }
    return 0;
}