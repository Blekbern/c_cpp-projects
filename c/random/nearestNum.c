#include <stdio.h>
#include <math.h>


int nearestNum( int num1, int num2 ) {
    
    if( num1 == num2 )
        return 0;
    else
        if( fabs( num1 - 100 ) > fabs( num2 - 100 ) )
            return num2;
        else
            return num1;
}

int main( void ) {
    int num1, num2;
    printf( "Enter 2 integers.\n" );
    if( scanf( "%d %d", &num1, &num2 ) != 2 ) {
        printf( "Invalid input.\n" );
        return 1;
    }

    if( num1 == num2 )
        printf( "The numbers are equal - %d\n", nearestNum( num1, num2 ) );
    else
        printf( "The number nearest to 100 is %d.\n", nearestNum( num1, num2 ) );
    return 0;
}