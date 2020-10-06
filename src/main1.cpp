#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "task1.h"

using namespace std;

int main() {
	int arr[LARGE_SIZE];
	int arr_copy[LARGE_SIZE];
	// Ðàíäîìèçàöèÿ ïî òàéìåðó
	srand(time(nullptr));
	// ãåíåðèðóåì ñëó÷àéíûå äàííûå
	generate(arr, arr + LARGE_SIZE, rnd());
	copy(arr, arr + LARGE_SIZE, arr_copy);
	// çàñåêàåì âðåìÿ
	time_t start = clock();
	// âûïîëíÿåì ñîðòèðîâêó, èñïîëüçóÿ ôóíêöèþ qsort
	qsort(arr, LARGE_SIZE, sizeof(int), comp);
	cout << "C quick-sort time elapsed: " << static_cast<double>(clock() - start) / CLOCKS_PER_SEC << "\n";
	// ñíîâà çàñåêàåì âðåìÿ
	start = clock();
	// âûïîëíÿåì ñîðòèðîâêó, èñïîëüçóÿ àëãîðèòì Ñ++
	sort(arr_copy, arr_copy + LARGE_SIZE);
	cout << "C++ quick-sort time elapsed: " << static_cast<double>(clock() - start) / CLOCKS_PER_SEC << "\n";
	return 0;

	system("pause");
}
