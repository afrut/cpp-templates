// This program demonstrates the use of classes with overloaded operators

#include <iostream>
#include "CTest.h"

using namespace std;

int main()
{
	CTest obj1;

    obj1.setVal(5);
	obj1.setName("obj1");

	CTest obj2 = CTest(3, "obj2");

    obj1.print();
    cout << "\n\n";
    obj2.print();
    cout << "\n\n";

    CTest obj3 = obj1 + obj2;
    obj3.setName("obj3");
    cout << "obj3 = obj1 + obj2\n";
    obj3.print();
    cout << "\n\n";

    cout << "obj4 = obj3\n";
    CTest obj4 = obj3;
    obj4.setName("obj4");
    obj4.print();

	cin.get();
}
