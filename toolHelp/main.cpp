// this program explores Tool Help Library from Microsoft Windows

#include <iostream>
#include "toolHelp.h"

using namespace std;

int main()
{
    PROCESSENTRY32 proc;
    BOOL processFound = false;
    const char* procName = "Minesweeper X.exe";

    // get the process handle by name
    processFound = getProcessHandle( procName, &proc );
    if ( processFound )
    {
        // print the process name for debugging purposes
        printf( "Process Name: %s\n", proc.szExeFile );
    }

    printf( "Threads Ids:\n" );
    listThreadIds( procName );

    printf( "Module Names:\n" );
    listModuleNames( procName );

    printf( "Heap Ids:\n" );
    listHeapBlocks( procName );
    getchar();
}
