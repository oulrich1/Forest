//
//  utility.h
//  RedBlackTree
//
//  Created by Oriah Ulrich on 2/3/15.
//  Copyright (c) 2015 Oriah Ulrich. All rights reserved.
//

#ifndef __RedBlackTree__utility__
#define __RedBlackTree__utility__

#include <stdio.h>

namespace Utility
{
    
    
/* (v->e1()->e2()->e3(p)) - except returns NULL when an 
   object is NULL by short circuiting with ternaries */
#define OPTIONAL( v, e1, e2, e3, p )    \
(                               \
(( v                         \
? v->e1()                   \
: NULL)                     \
? v->e1()->e2()             \
: NULL)                     \
? v->e1()->e2()->e3(p)      \
: NULL                      \
)
    
    
    template <typename T>
    inline bool is_within(T val, T min, T max)
    {
        return ( val >= min && val < max );
    }
} // namespace Utility

#endif /* defined(__RedBlackTree__utility__) */
