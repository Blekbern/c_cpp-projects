#include <stdio.h>
#include <stdlib.h>

void shiftNumbers( int numArray[], int numArrLen ) {
    int index = 0, tmp;
    for( int i = 0; i < numArrLen; i++ ) {
        if( (numArray[i] % 2) == 0 ) {
            tmp = numArray[index];
            numArray[index] = numArray[i];
            numArray[i] = tmp;
            
            index++;
        }
    }
}

void printArray( int numArray[], int numArrLen ) {
    printf( "The elements are: " );
    for( int i = 0; i < numArrLen; i++ ) {
        if( i )
            printf( " " );
        printf( "%d", numArray[i] );
    }
    printf( "\n" );
}

int main( void ) {
    int * numArray = NULL, *tmp = NULL;
    int cap = 10, err;
    numArray = (int*)malloc( cap * sizeof(int) );
    if( !numArray ) {
        printf( "Failed to allocate memory.\n" );
        return 1;
    }
    printf( "Enter numbers.\n" );
    int i = 0;
    while( (err = scanf( "%d", &numArray[i] )) == 1 ) {
        i++;
        if( i > cap - 1 ) {
            cap *= 2;
            tmp = (int*)realloc( numArray, cap * sizeof(int) );
            if( !tmp ) {
                printf( "Failed to reallocate memory.\n" );
                free( numArray );
                return 1;
            }
            numArray = tmp;
        }
    }
    if( err != EOF ) {
        printf( "Invalid input.\n" );
        free( numArray );
        return 1;
    }
    
    printArray( numArray, i );
    shiftNumbers( numArray, i );
    printArray( numArray, i );
    return 0;
}