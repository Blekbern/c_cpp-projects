#include <stdio.h>

void addition( int num1, int num2, int * sum ) {
    if( num1 == num2 )
        *sum = (num1 + num2) * 3;
    else
        *sum = (num1 + num2);
}


int main( void ) {
    int num1, num2, sum;
    printf( "Insert 2 integers to sum up.\n" );
    if( scanf( "%d %d", &num1, &num2 ) != 2 ) {
        printf( "Invalid input.\n" );
        return 1;
    }
    addition( num1, num2, &sum );
    if( num1 == num2 )
        printf( "The tripled sum of the same numbers is %d.\n", sum );
    else
        printf( "The sum is %d.\n", sum );
    return 0;
}