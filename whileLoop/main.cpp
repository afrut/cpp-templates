// this program contains an infinite while loop that increments
// a global variable

// this program was intended to be used as a target process
// for memory reading by a separate program

#include <iostream>
#include <thread> // for sleep_for()
#include <chrono> // for seconds()

using namespace std;

// target global variable for memory reading
long counter;

int main()
{
    counter = 0;
    while(true)
    {
        counter++;
		cout << "counter = " << dec << counter;

        // display address of counter
		cout << " counter address = " <<
			 hex << &counter << "\n";

        // pause execution for 2 seconds
        this_thread::sleep_for(chrono::seconds(2));
    }
}
