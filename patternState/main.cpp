#include <stdio.h> // for printf function
#include <iostream> // for cin.get()
#include "Tank.h"

using namespace std; // for cin.get()

int main()
{
    Tank tank;
	cout << "level: " << tank.level() << ", temp: " << tank.temp();
	cin.get();
}
