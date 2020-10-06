
#include "task1.h"

using namespace std;

int comp( const void* a, const void* b ) {
    return ( *( int* )a - *( int* )b );
}
