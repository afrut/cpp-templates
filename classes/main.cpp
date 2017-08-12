// This program demonstrates the use of classes with overloaded operators

#include <iostream>
#include "CTest.h"

using namespace std;

int main()
{
    // use default constructor to create object 1
	CTest obj1;

    // use setters to set name and value of object 1
    obj1.setVal(5);
	obj1.setName("obj1");

    // display object 1
    obj1.print();
    cout << "\n\n";

    // create object 2 using a different constructor
	CTest obj2 = CTest(3, "obj2");

    // display object 2
    obj2.print();
    cout << "\n\n";

    // add object 1 and object 2 using overloaded + operator
    CTest obj3 = obj1 + obj2;

    // set name of object 3
    obj3.setName("obj3");

    // display object 3
    cout << "obj3 = obj1 + obj2\n";
    obj3.print();
    cout << "\n\n";

    // create object 4 using overloaded = operator
    CTest obj4 = obj3;
    obj4.setName("obj4");

    // display object 4
    cout << "obj4 = obj3\n";
    obj4.print();

	cin.get();
}
