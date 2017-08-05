// this program demonstrates the declaration, implementation
// and usage of a tempalte function

#include <stdio.h>
#include <iostream>
#include "templateHeader.h"

using namespace std;

int main()
{
    int int1 = 1;
    int int2 = 2;
    cout << "adding int's: " << int1 << " + " << int2 << " = " << add( int1, int2 );
    cout << "\n";

    double dbl1 = 3;
    double dbl2 = 4;
    cout << "adding double's: " << dbl1 << " + " << dbl2 << " = " << add( dbl1, dbl2 );
    cout << "\n";

    float flt1 = 5;
    float flt2 = 6;
    cout << "adding float's: " << flt1 << " + " << flt2 << " = " << add( flt1, flt2 );
    cout << "\n\n";

    CMyClass obj1 = CMyClass( 1, 2.0, 3.0f );
    obj1.setName( "obj1" );

    CMyClass obj2 = CMyClass( 4, 5.0, 6.0f );
    obj2.setName( "obj2" );

    obj1.print();
    obj2.print();

    cout << "\n";
    cout << "adding objects: \n";

    CMyClass obj3 = add( obj1, obj2 );
    obj3.setName( "obj3" );
    obj3.print();
    
    cin.get();
}
