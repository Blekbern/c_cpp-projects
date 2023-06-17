#include <stdio.h>

int checkNumbers( int num1, int num2 ) {
    if( num1 == 30 || num2 == 30 )  return 1;
    if( num1 + num2 == 30 )         return 2;
    else                            return 0;
}

int main( void ) {
    int num1, num2, result;

    printf( "Insert 2 integers:\n" );
    if( scanf( "%d %d", &num1, &num2 ) != 2 ) {
        printf( "Invalid input.\n" );
        return 1;
    }
    result = checkNumbers( num1, num2 );
    if( result == 1 )
        printf( "One of the numbers is 30.\n" );
    if( result == 2 )
        printf( "The sum of the numbers is 30.\n" );
    if( result == 0 )
        printf( "Neither numbers are 30 nor their sum.\n" );    

    return 0;
}