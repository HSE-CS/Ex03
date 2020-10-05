//
//  task1.cpp
//  task1
//
//  Created by Julia Rogozyan on 05.10.2020.
//  Copyright © 2020 Julia Rogozyan. All rights reserved.
//

#include "../include/task1.h"

int comp( const void* a, const void* b ) {
    return ( *( int* )a - *( int* )b );
}
