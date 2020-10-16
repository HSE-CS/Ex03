#include <iostream>
#include "task1.h"
using namespace std;

int main() {
	for (int i = 10; i < 70; i+=2) {
		SortCompare(1000000 / i);
	}

	return 0;
}