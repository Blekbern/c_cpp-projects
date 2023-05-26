#include <stdio.h>
#include <math.h>

void difference( int num1, int * diff ) {
    if( num1 > 51 ) 
        *diff = fabs( 3 * (num1 - 51) );
    else
        *diff = fabs( num1 - 51 );
}


int main( void ) {
    int num1, diff;
    
    printf( "Put an integer in.\n" );
    if( scanf( "%d", &num1 ) != 1 ) {
        printf( "Invalid input.\n" );
        return 1;
    }
    
    difference( num1, &diff );
    
    if( num1 > 51 )
        printf( "The tripled absolute difference is %d.\n", diff );
    else
        printf( "The absolute difference is %d.\n", diff );
    return 0;
}