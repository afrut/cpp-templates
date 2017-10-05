// this program contains an infinite while loop that increments
// a global variable

#include <iostream>
#include <thread> // for sleep_for()
#include <chrono> // for seconds()

using namespace std;

// global variable
int counter;

int main()
{
    counter = 0;
    while(true)
    {
        counter++;
		cout << "counter = " << dec << counter;

        // display address of counter
		cout << " counter address = 0x" <<
			 hex << &counter << "\n";

        // pause execution for 2 seconds
        // this_thread::sleep_for(chrono::seconds(2));
        getchar();
    }
}
