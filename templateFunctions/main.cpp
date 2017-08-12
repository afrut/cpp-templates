// this program demonstrates the declaration, implementation
// and usage of a template function

#include <stdio.h>
#include <iostream>
#include "templateHeader.h"

using namespace std;

int main()
{
    // the add() function is used on different data types

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

    // create objects
    CMyClass obj1 = CMyClass( 1, 2.0, 3.0f );
    obj1.setName( "obj1" );
    CMyClass obj2 = CMyClass( 4, 5.0, 6.0f );
    obj2.setName( "obj2" );

    // display objects
    obj1.print();
    obj2.print();

    // use the add() function to add two different objects
    // class of objects has to have overloaded + operator
    CMyClass obj3 = add( obj1, obj2 );
    cout << "\n";
    cout << "adding objects: \n";
    obj3.setName( "obj3" );
    obj3.print();
    
    cin.get();
}
