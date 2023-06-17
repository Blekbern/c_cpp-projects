#include <stdio.h>

// higher num in a range of 20 and 30
// if out of bounds return 0

int readInput( int * number ) {
    if( scanf( "%d", number ) != 1 ) {
        printf( "Invalid input.\n" );
        return 0;
    }
    return 1;
}


int higherNum( int num1, int num2, int LO, int HI ) {
    if( (num1 <  LO || num1 >  HI) && (num2 <  LO || num2 >  HI) )                  return 0;
    if(  num1 >= LO && num1 <= HI  &&  num2 >= LO && num2 <= HI && num1 > num2 )    return num1; 
    if(  num2 >= LO && num2 <= HI  &&  num1 >= LO && num1 <= HI && num2 > num1 )    return num2; 
    if(  num1 >= LO && num1 <= HI  && (num2 <  LO || num2 >  HI) )                  return num1; 
    if(  num2 >= LO && num2 <= HI  && (num1 <  LO || num1 >  HI) )                  return num2;
    return 0;
}


int main( void ) {
    int LO, HI, num[2], answer;
    printf( "Enter lower bound:\n" );
    if( !readInput( &LO ) ) {
        return 1;
    }

    printf( "Enter upper bound:\n" );
    if( !readInput( &HI ) || HI < LO ) {
        if( HI < LO ) {
            printf( "Upper bound must be higher than lower bound.\n" );
            return 1;
        }
        return 1;
    }

    printf( "Enter two numbers.\n" );
    for( int i = 0; i < 2; i++ ) {
        readInput( &num[i] );
    }

    if( !(answer = higherNum( num[0], num[1], LO, HI )) ) {
        printf( "Neither numbers are in the bounds.\n" );
    } else {
        printf( "The bigger number is %d.\n", answer );
    }

    return 0;
}