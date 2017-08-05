// NOTES:
// - string class is a typedef for basic_string<char>
// - wstring class is a typedef for basic_string<wchar_t>

// make functions generic by using templates because
// we expect either char or wchar_t types

using namespace std;

#include <string>

template<typename T>
void rpadws( basic_string<T>& s // T to be resolved to char or wchar_t
         , typename basic_string<T>::size_type n ) // length to pad to
        
{
    s.append( n - s.length(), ' ' );
}

// left pad with spaces
template<typename T>
void lpadws( basic_string<T>& s
           , typename basic_string<T>::size_type n )
{
    s.insert( s.begin(), n - s.length(), ' ' );
}

// right trim whitespaces
template<typename T>
void rtrimws( basic_string<T>& s );
{
    if ( s.emptry() )
        return;

    typename basic_string<T>::iterator p;

    for ( p = s.end(); p != s.begin() && *--p == c;);
}

//void rtrimws( string& s )
//{
//}

//// left trim whitespaces
//void ltrimws( string& s )
//{
//}
