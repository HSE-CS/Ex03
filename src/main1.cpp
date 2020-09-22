#include "task1.h"

using namespace std;

int main() {
    int arr[LARGE_SIZE];
    int arr_copy[LARGE_SIZE];

    int razmer = 0;
    // ������������ �� �������
    ofstream filik;
    filik.open("D:/GIT/Ex03/data/result.txt");

    for (int i = 0; i < 50; i++)
    {
        //cout << i << "\n";
        srand(time(nullptr));
        // ���������� ��������� ������
        razmer = i * 1800;
        generate(arr, arr + razmer, rnd());
        copy(arr, arr + razmer, arr_copy);
        // �������� �����
        time_t start = clock();
        // ��������� ����������, ��������� ������� qsort
        qsort(arr, razmer, sizeof(int), comp);
        filik << razmer <<"\t";
        filik << static_cast<double>(clock() - start) / CLOCKS_PER_SEC << "\t";
        // ����� �������� �����
        start = clock();
        // ��������� ����������, ��������� �������� �++
        sort(arr_copy, arr_copy + razmer);
        filik << static_cast<double>(clock() - start) / CLOCKS_PER_SEC << "\n";
    }
    filik.close();
    return 0;
}
