//
//  main.cpp
//  task1
//
//  Created by Julia Rogozyan on 05.10.2020.
//  Copyright © 2020 Julia Rogozyan. All rights reserved.
//


#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include "../include/task1.h"

using namespace std;

void testSorts(int n);

int main() {
    cout <<"SIZE        QSORT         SORT"<<endl;
    int n = 400;
    for(int i =0; i < 50; i++, n += 50)
        testSorts(n);
    return 0;
}

void testSorts(int n) {
    int* a = NULL;
    int* a_copy = NULL;
    cout<<n<<"        ";
    a = new int[n];
    a_copy = new int[n];
    srand(time(nullptr));
    generate( a, a + n, rnd() );
    copy( a, a + n, a_copy );
    time_t start = clock();
    qsort( a, n, sizeof( int ), comp );
    // cout << "C quick-sort time elapsed: " << static_cast<double>( clock() - start ) / CLOCKS_PER_SEC << "\n";
    cout <<static_cast<double>( clock() - start ) / CLOCKS_PER_SEC <<"        ";
    start = clock();
    sort( a_copy, a_copy + n );
    cout <<static_cast<double>( clock() - start ) / CLOCKS_PER_SEC <<"        "<<endl;
    delete [] a;
    a = NULL;
    delete [] a_copy;
    a_copy = NULL;
}
