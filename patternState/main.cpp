// this program demonstrates printing output to the console
// and pausing until the user inputs a character using
// C and C++ functions

#include <stdio.h> // for printf function
#include <iostream> // for cin.get()
#include "Tank.h"

using namespace std; // for cin.get()

int main()
{
    Tank tank(25, 50, 25);
	std::cout << tank.toString().c_str();
	cin.get();
}
