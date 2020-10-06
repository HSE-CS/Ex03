#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "task1.h"

using namespace std;
int comp( const void* a, const void* b )
{
	return ( *( int* )a - *( int* )b );
}
void realizesort()
{
	int LARGE_SIZE = 10000;
	double timeqsort[51];
	int sizearr[51];
	double timesort[51];

	srand(time(nullptr));

	for(int i =1; i < 51; i++)
	{
		if(i % 10 == 0)
			LARGE_SIZE *= 2;
        int arr[LARGE_SIZE];
        int arr_copy[LARGE_SIZE];


		generate(arr,arr + LARGE_SIZE,rnd());
		copy(arr,arr+LARGE_SIZE,arr_copy);
		time_t start = clock();
		qsort(arr,LARGE_SIZE,sizeof(int),comp);
		timesort[i] = static_cast<double>( clock() - start ) / CLOCKS_PER_SEC;
		sizearr[i] = LARGE_SIZE;

		cout << "C quick-sort time elapsed: " << static_cast<double>( clock() - start ) / CLOCKS_PER_SEC <<" " << LARGE_SIZE << "\n";
		start = clock();
    // выполняем сортировку, используя алгоритм С++
    	sort( arr_copy, arr_copy + LARGE_SIZE );
    	timeqsort[i] = static_cast<double>( clock() - start ) / CLOCKS_PER_SEC;
    	cout << "C++ quick-sort time elapsed: " << static_cast<double>( clock() - start ) / CLOCKS_PER_SEC << " " << LARGE_SIZE << "\n";
	}
	cout << "Size || C Sort || C++ Sort \n";
	for(int i = 1; i < 51; i++)
	{

		cout << sizearr[i]  << " | " << timesort[i] << " | " << timeqsort[i] <<   "\n";
	}


}