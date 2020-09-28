#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include "task1.h"


using namespace std;


int main()
{
    double data[51][3];
    int j = 0;
    for (int i = 2000; i <= LARGE_SIZE;)
    {
        int* arr = (int*)malloc(sizeof(int) * i);
        int* arr_copy = (int*)malloc(sizeof(int) * i);
        data[j][0] = i;

        srand(time(nullptr));

        // генерируем случайные данные
        generate(arr, arr + i, rnd());
        copy(arr, arr + i, arr_copy);


        time_t start = clock();


        qsort(arr, i, sizeof(int), comp);
        data[j][1] = static_cast<double>(clock() - start) / CLOCKS_PER_SEC;
        // cout << "C quick-sort time elapsed: " << static_cast<double>(clock() - start) / CLOCKS_PER_SEC << "\n";

         // снова засекаем врем€
        start = clock();

        // выполн€ем сортировку, использу€ алгоритм —++
        sort(arr_copy, arr_copy + i);
        data[j][2] = static_cast<double>(clock() - start) / CLOCKS_PER_SEC;
        //cout << "C++ quick-sort time elapsed: " << static_cast<double>(clock() - start) / CLOCKS_PER_SEC << "\n";

        if (i == 2000)
            i = 20000;
        else
            i += 20000;

        j++;
    }

    for (int i = 0; i <= 50; i++)
        cout << "N: " << data[i][0] << "\t" << "Qs: " << data[i][1] << "\t" << "S: " << data[i][2] << "\n";
    return 0;
}