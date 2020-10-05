#include "task1.h"

using namespace std;

int main() {
    int *arr = new int [LARGE_SIZE];
    int *arr_copy = new int [LARGE_SIZE];
    int size;
    // ������������ �� �������
    for (int size = 10000;  size <= LARGE_SIZE; size += 10000)
    {
        srand(time(nullptr));
        // ���������� ��������� ������
        generate( arr, arr + size, rnd() );
        copy( arr, arr + size, arr_copy );
        // �������� �����
        time_t start = clock();
        // ��������� ����������, ��������� ������� qsort
        qsort( arr, size, sizeof( int ), comp );
        cout << size << " " << "C quick-sort time: " << static_cast<double>( clock() - start ) / CLOCKS_PER_SEC << " ";
        // ����� �������� �����
        start = clock();
        // ��������� ����������, ��������� �������� �++
        sort( arr_copy, arr_copy + size );
        cout << "C++ quick-sort time: " << static_cast<double>( clock() - start ) / CLOCKS_PER_SEC << "\n";
    }
    return 0;
}
