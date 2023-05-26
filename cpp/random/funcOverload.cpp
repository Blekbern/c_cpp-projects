#include <iostream>

int addition( int a, int b ) {
    return a + b;
}

double addition( double a, double b ) {
    return a + b;
}

float addition( float a, float b, float c ) {
    return a + b + c;
}


int main( void ) {

    cout << addition( 2, 3 ) << endl;
    cout << addition( 2.2, 3.3 ) << endl;
    cout << addition( 2.2, 3.3, 4.4 ) << endl;

    // cout << addition( 2, 3.3 ) << endl; ---> won't compile - error call of overloaded function ambigous 

    return 0;
}