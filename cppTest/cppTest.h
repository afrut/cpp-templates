// god header

#ifndef _CPPTESTH
#define _CCPTESTH

using namespace std;

#include <iostream>

// template function implementations need to be in the header file
// best practice is to put the implementation in cpp file and use #include
#include "fnTemplate.cpp"

// string functions
template<typename T>
void rpadws( basic_string<T>& s // T to be resolved to char or wchar_t
           , typename basic_string<T>::size_type n ); // length to pad to

template<typename T>
void lpadws( basic_string<T>& s
           , typename basic_string<T>::size_type n );

void rtrimws( string& s );
//void ltrimws( string& s );
#include "fnString.cpp"

#include "CTest.h"

#endif
