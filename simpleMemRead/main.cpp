#include <iostream>
#include <windows.h>
#include <tlhelp32.h>
#include <tchar.h>
#include <thread> // for sleep_for() 
#include <chrono> // for seconds()


// Forward declarations:
BOOL getProcess( const char* processName, PROCESSENTRY32* ret );
void printError(TCHAR* msg);



int main( void )
{
    // memory value
    int memVal;

    // retrieve the PROCESSENTRY32 structure containing process information
    PROCESSENTRY32 pe32;
	BOOL ret = getProcess( "whileLoop.exe", &pe32 );
    std::cout << std::hex << "Process ID: " << pe32.th32ProcessID << "\n";

    // open handle to the target process
    HANDLE hProcess = OpenProcess(PROCESS_VM_READ, 0, pe32.th32ProcessID);

    // define the target's memory address that you would like to read
    LPCVOID address = (LPCVOID)0x00B1D138;

    while( true )
    {
        // read the memory address of target process
        ReadProcessMemory( hProcess, address, &memVal, sizeof(memVal), 0 );

        std::cout << "Address " << std::hex << address <<
                " has value " << std::dec << memVal << "\n";
        std::this_thread::sleep_for( std::chrono::seconds(1) );
    }

    // close handle to the target process
    CloseHandle( hProcess );

	return 0;
}



// used to retrieve the process ID using the process name
BOOL getProcess( const char* processName, PROCESSENTRY32* ret )
{
	HANDLE hProcessSnap;
	HANDLE hProcess;
	PROCESSENTRY32 pe32;
	DWORD dwPriorityClass;

	// Take a snapshot of all processes in the system.
	hProcessSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	if (hProcessSnap == INVALID_HANDLE_VALUE)
	{
		printError(TEXT("CreateToolhelp32Snapshot (of processes)"));
		return(FALSE);
	}

	// Set the size of the structure before using it.
	pe32.dwSize = sizeof(PROCESSENTRY32);

	// Retrieve information about the first process,
	// and exit if unsuccessful
	if (!Process32First(hProcessSnap, &pe32))
	{
		printError(TEXT("Process32First")); // show cause of failure
		CloseHandle(hProcessSnap);          // clean the snapshot object
		return(FALSE);
	}

	// Now walk the snapshot of processes, and
	// display information about each process in turn
	do
	{
		if (strcmp(pe32.szExeFile, "whileLoop.exe") == 0)
		{
            *ret = pe32;
            break;
		}
	} while (Process32Next(hProcessSnap, &pe32));

	CloseHandle(hProcessSnap);
	return(TRUE);
}


// used to print errors in function getProcess
void printError(TCHAR* msg)
{
	DWORD eNum;
	TCHAR sysMsg[256];
	TCHAR* p;

	eNum = GetLastError();
	FormatMessage(FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
		NULL, eNum,
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), // Default language
		sysMsg, 256, NULL);

	// Trim the end of the line and terminate it with a null
	p = sysMsg;
	while ((*p > 31) || (*p == 9))
		++p;
	do { *p-- = 0; } while ((p >= sysMsg) &&
		((*p == '.') || (*p < 33)));

	// Display the message
	_tprintf(TEXT("\n  WARNING: %s failed with error %d (%s)"), msg, eNum, sysMsg);
}
