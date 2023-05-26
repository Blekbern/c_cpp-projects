#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
using namespace std;

int letterDistance( string str1, string str2 ) {
    int dist = 0;
    if( str1.size() >= str2.size() ) {
        for( uint i = 0; i < str2.size(); i++ ) {
            dist += fabs( str1[i] - str2[i] );
        }
        dist += fabs( str1.size() - str2.size() );
    } else {
        for( uint i = 0; i < str1.size(); i++ ) {
            dist += fabs( str1[i] - str2[i] );
        }
        dist += fabs( str2.size() - str1.size() );
    }
    return dist;
}


int main( void ) {
    cout << letterDistance( "house", "fly" ) << endl;
    cout << letterDistance( "sharp", "sharq" ) << endl;
    cout << letterDistance( "abcde", "Abcde" ) << endl;
    cout << letterDistance( "abcde", "bcdef" ) << endl;
    cout << letterDistance( "very", "fragile" ) << endl;


    return 0;
}