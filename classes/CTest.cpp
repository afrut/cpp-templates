#include <iostream>
#include "CTest.h""

// default constructor
CTest::CTest() :
    // member initialization list
    m_val( 0 )
  , m_name( "" )
{
}


// another type of constructor
CTest::CTest( const char* name ) :
    m_val( 0 )
  , m_name( name )
{
}



// yet another type of constructor
CTest::CTest( int p, const char* name ) :
	m_val( p )
  , m_name( name )
{
}



// again, another type of constructor
CTest::CTest( int p ) :
	m_val( p )
{
}



// destructor
CTest::~CTest()
{
}



// overloaded + operator
// const an object reference if it should not be changed
// const a non-static member function if it doesn't change the object
CTest CTest::operator+( const CTest& a ) const
{
    return CTest( a.getVal() + m_val );
}



// overloaded = operator
CTest CTest::operator=( const CTest& a ) const
{
    return CTest( a.getVal() );
}



void CTest::print()
{
    cout << m_name << ":\n";
    cout << "   m_val: " << m_val << "\n";
}
