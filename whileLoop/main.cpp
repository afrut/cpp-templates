#include <iostream>
#include <thread> // for sleep_for()
#include <chrono> // for seconds()

using namespace std;

long counter;

int main()
{
    counter = 0;
    while(true)
    {
        counter++;
        cout << "counter = " << counter << "\n";
        this_thread::sleep_for(chrono::seconds(2));
    }
}
