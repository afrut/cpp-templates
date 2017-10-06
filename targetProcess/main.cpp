// this program is meant to be a target process for memory a memory scanner

#include<stdio.h>
#include<inttypes.h> // for PRId64 and PRIu64 format specifies

// declare some global variables of all fundamental types
bool                    gblBool = true;

char                    gblChar = 0;
unsigned char           gblUChar = 0;

short                   gblShort = 0;
unsigned short          gblUShort = 0;

int                     gblInt = 0;
unsigned int            gblUInt = 0;

float                   gblFloat = 0;
double                  gblDouble = 0;

long                    gblLong = 0;
unsigned long           gblULong = 0;

void main()
{
    while( true )
    {
		// increment all local variables
        gblBool = !gblBool;
        if( gblChar == 127 ) gblChar = 0;
        else gblChar++;
		if( gblUChar == 255 ) gblUChar = 0;
		else gblUChar++;
        gblShort++;
        gblUShort++;
        gblInt++;
        gblUInt++;
        gblFloat++;
        gblDouble++;
        gblLong++;
        gblULong++;

		// print values and addresses of global variables
		printf( "---------------------------------------------\n" );
        printf( "gblBool         = %-8s(0x%p)\n", gblBool ? "true" : "false", (void*)&gblBool );
        printf( "gblChar         = %-8d(0x%p)\n", gblChar, (void*)&gblChar );
		printf( "gblUChar        = %-8d(0x%p)\n", gblUChar, (void*)&gblUChar );
        printf( "gblShort        = %-8d(0x%p)\n", gblShort, (void*)&gblShort );
        printf( "gblUShort       = %-8d(0x%p)\n", gblUShort, (void*)&gblUShort );
        printf( "gblInt          = %-8d(0x%p)\n", gblInt, (void*)&gblInt );
        printf( "gblUInt         = %-8d(0x%p)\n", gblUInt, (void*)&gblUInt );
        printf( "gblFloat        = %-8.2f(0x%p)\n", gblFloat, (void*)&gblFloat );
        printf( "gblDouble       = %-8.2f(0x%p)\n", gblDouble, (void*)&gblDouble );
        printf( "gblLong         = %-8d(0x%p)\n", gblLong, (void*)&gblLong );
        printf( "gblULong        = %-8d(0x%p)\n", gblULong, (void*)&gblULong );

        // pause to view values
        getchar();
    }
}
