#include <math.h>
#include <stdio.h>
#include "task1.h"

int comp( const void* a, const void* b ) {
    return ( *( int* )a - *( int* )b );
}
