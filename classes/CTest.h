#include <string> // for string class

using namespace std; // for string class

#ifndef _CTEST_H
#define _CTEST_H

class CTest
{
    public:
        // constructors can be used to set different attributes upon creation
        CTest(); // default constructor
		CTest( const char * name ); // another type of constructor
		CTest( int p, const char * name ); // yet another type of constructor
		CTest( int p ); // again, another type of constructor

        // default destructor
        virtual ~CTest();

    private:
        int m_val;
		string m_name;
    
    public:
        // setters
        void setVal( int p ) { m_val = p; };
		void setName(const char* p) { m_name = p; };
    
    public:
        // getters
        int getVal() const { return m_val; };
		const string& getName() const { return m_name; };
        void print();
    
    public:
        // overloaded operators
        CTest operator+( const CTest& a ) const;
        CTest operator=( const CTest& a ) const;
};

#endif
