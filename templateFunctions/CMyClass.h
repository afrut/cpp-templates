#ifndef _MY_CLASS_H
#define _MY_CLASS_H

#include <string>

using namespace std;

class CMyClass
{
    public:
        CMyClass(); // default constructor
        CMyClass(int p1, double p2, float p3); // another constructor
        virtual ~CMyClass(); // destructor

    private:
        int m_int;
        double m_dbl;
        float m_flt;
        string m_name;

    public:
        int getInt() const { return m_int; };
        double getDbl() const { return m_dbl; };
        float getFlt() const { return m_flt; };
        const char* getName() const { return m_name.c_str(); };

    public:
        void setInt( int p ) { m_int = p; };
        void setDbl( double p ) { m_dbl = p; };
        void setFlt( float p) { m_flt = p; };
        void setName( const char* name ) { m_name = name; };

    public: 
        void print();
        CMyClass operator+( const CMyClass& a ) const;
};

#endif
