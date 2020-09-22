#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>

#include "task1.h"

using namespace std;

const size_t LARGE_SIZE = 100000;

struct rnd {
    int operator()() {
        return rand() % LARGE_SIZE;
    }
};



int main() {

    int arr[LARGE_SIZE];
    int arr_copy[LARGE_SIZE];
    ofstream fout;
    fout.open("C:\\Users\\nikit\\source\\repos\\ex03\\ex03\\results.txt");
    for (int i = 0; i < 50; i++) {
        // ������������ �� �������
        srand(time(nullptr));
        // ���������� ��������� ������
        generate(arr, arr + LARGE_SIZE, rnd());
        copy(arr, arr + LARGE_SIZE, arr_copy);
        // �������� �����
        time_t start = clock();
        // ��������� ����������, ��������� ������� qsort
        qsort(arr, LARGE_SIZE, sizeof(int), comp);
        fout <<i<<" " << static_cast<double>(clock() - start) / CLOCKS_PER_SEC << "  ";
        // ����� �������� �����
        start = clock();
        // ��������� ����������, ��������� �������� �++
        sort(arr_copy, arr_copy + LARGE_SIZE);
        fout << static_cast<double>(clock() - start) / CLOCKS_PER_SEC << "\n";
        
    }
    fout.close();
    return 0;
}