#include "task1.h"

#include "gtest/gtest.h"


TEST(task1,comp1)
{
	const size_t n = 6;
	int *arr = new int[n]{5, 3, 2, 4, 1, 6};
	qsort(arr,n,sizeof(int),comp);
	int *expected = new int[n]{1, 2, 3, 4, 5, 6};
    
        for(size_t i = 0; i < n; i++)
		EXPECT_EQ(expected[i], arr[i]);

	delete[] arr;
	delete[] expected;
}
