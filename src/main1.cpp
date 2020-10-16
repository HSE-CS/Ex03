#include "task1.h"
#include <fstream>
using namespace std;

int main() {
	//ofstream out("rezults.txt");
	//out << "size   qsort    sort\n";
	int arr[LARGE_SIZE];
	int arr_copy[LARGE_SIZE];
	unsigned size = 2000;
	for (int i=0; i < 50; ++i) {
		//out << size<<' ';
		cout << size << " ";
		srand(time(nullptr));
		generate(arr, arr + size, rnd());
		copy(arr, arr + size, arr_copy);
		time_t start = clock();
		qsort(arr, size, sizeof(int), comp);
		//out << static_cast<double>(clock() - start) / CLOCKS_PER_SEC << " ";
		cout << static_cast<double>(clock() - start) / CLOCKS_PER_SEC << " ";
		start = clock();
		sort(arr_copy, arr_copy + size);
		//out << static_cast<double>(clock() - start) / CLOCKS_PER_SEC << "\n";
		cout << static_cast<double>(clock() - start) / CLOCKS_PER_SEC << "\n";
		size += 2000;
		//
	}
	return 0;
}