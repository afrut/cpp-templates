#ifndef _TEMPLATE_HEADER_H
#define _TEMPLATE_HEADER_h

// sample template function to add any types
template <typename T>
T add ( T t1, T t2 );
// function declarations and their implementations are to be kept separate
// however, for template functions, it is good to put the implementation in
// the header file. A good solution is to include the cpp file in the
// header file
#include "add.cpp"

#include "CMyClass.h"

#endif
