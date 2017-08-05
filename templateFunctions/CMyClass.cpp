#include "CMyClass.h"
#include <iostream>

// default constructor
CMyClass::CMyClass() :
    m_int( 0 )
  , m_dbl( 0 )
  , m_flt( 0 )
{
}



// another constructor
CMyClass::CMyClass( int p1
                  , double p2
                  , float p3 )
{
    m_int = p1;
    m_dbl = p2;
    m_flt = p3;
}



// destructor
CMyClass::~CMyClass()
{
}



// print function
void CMyClass::print()
{
    cout << "name: " << this->getName() << "\n";
    cout << "    int: " << this->getInt() << "\n";
    cout << "    dbl: " << this->getDbl() << "\n";
    cout << "    flt: " << this->getFlt() << "\n";
}



// overloaded + operator
CMyClass CMyClass::operator+( const CMyClass& a ) const
{
    return CMyClass( a.getInt() + m_int
                   , a.getDbl() + m_dbl
                   , a.getFlt() + m_flt );
}
