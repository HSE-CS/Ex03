#ifndef TASK1_CPP
#define TASK1_CPP

#include "task1.h"

int comp( const void* a, const void* b ) {
    return ( *( int* )a - *( int* )b );
}

/*
void printTests(double arr[3][TEST_AMOUNT]) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < TEST_AMOUNT; ++j) {
            cout << tests[i][j] << ' ';
        }
        cout << '\n';
    }
}
 */

#endif //TASK1_CPP