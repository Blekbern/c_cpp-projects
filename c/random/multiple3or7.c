#include <stdio.h>
#include <math.h>

int multiple( int num1 ) {
    if( num1 % 3 == 0 && num1 % 7 == 0 ) return 1;
    if( num1 % 3 == 0 )                  return 2;
    if( num1 % 7 == 0 )                  return 3;
    else                                 return 0;
}


int main( void ) {
    int num1, result;
    printf( "Enter an integer.\n" );
    if( scanf( "%d", &num1 ) != 1 ) {
        printf( "Invalid input.\n" );
        return 1;
    }
    result = multiple( num1 );
    switch( result ) {
        case 1:
            printf( "Number is a multiple of 3 and 7.\n" );
            break;
        case 2:
            printf( "Number is a multiple of 3.\n" );
            break;
        case 3:
            printf( "Number is a multiple of 7.\n" );
            break;
        default:
            printf( "Number is NOT a multiple of 3 or 7.\n" );
            break;
    }
    return 0;
}