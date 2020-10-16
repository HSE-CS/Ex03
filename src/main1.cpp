#include <iostream>
#include "task1.h"
using namespace std;

int main() {
    for (int i = 1; i < 55; i++){
      ComputeAndPrint(100000/i);
    }
    
    return 0;
}