// this program demonstrates the use of header files
// and functions defined in other files

#include <stdio.h>
#include <iostream>
#include "myHeader.h" // need this to use the function add One

using namespace std;

int main()
{
	printf("3 + 1 = %d", addOne(3));
	cin.get();
}
