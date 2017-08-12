// this program demonstrates printing output to the console
// and pausing until the user inputs a character using
// C and C++ functions

#include <stdio.h> // for printf function
#include <iostream> // for cin.get()

using namespace std; // for cin.get()

int main()
{
    // hello world C-style
	printf("Hello World from C\n");
	printf("Enter any character from C\n");
	getchar(); // pause and until user presses return to see output

    // hello world C++ style
	cout << "Hello again from C++ this time\n";
	cout << "Enter any character from C++\n";
	cin.get(); // pause and until user presses return to see output
}
