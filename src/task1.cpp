//
//  task1.cpp
//  cpp_exmp
//
//  Created by Сапожников Андрей Михайлович on 22.09.2020.
//  Copyright © 2020 Сапожников Андрей Михайлович. All rights reserved.
//

#include "task1.h"

int comp( const void* a, const void* b ) {
    return ( *( int* )a - *( int* )b );
}
