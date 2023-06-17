#include <stdio.h>
#include <math.h>

// Programme calculates whether the number is within the distance of number 100 or 200 by 10s
// returns 1 if the numbeer is within the distance
// else returns 0 if the number is not


int measureDist( int num1 ) {
    return fabs( num1 - 100 ) <= 10 || fabs( num1 - 200 ) <= 10;
}


int main( void ) {
    int num1;
    printf( "Enter an integer.\n" );
    if( scanf( "%d", &num1 ) != 1 ) {
        printf( "Invalid input.\n" );
        return 1;
    }
    printf( "%d\n", measureDist( num1 ) );
    return 0;
}