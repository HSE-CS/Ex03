#pragma once
#include<iostream>
#include<math.h>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include<stdio.h>
#include<iomanip>
using namespace std;
int comp(const void* a, const void* b);
const size_t LARGE_SIZE = 100000;
struct rnd {
	int operator()() {
		return rand() % LARGE_SIZE;
	}
};
