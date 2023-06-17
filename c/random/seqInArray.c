#include <stdio.h>
#include <stdlib.h>

int readInput( int number[] ) {
    int err;
    if( (err = scanf( "%d", number )) == 1 )
        return 1;
    if( err == EOF )
        return -1;
    return 0;
}

int compare( int * num1, int * num2 , int len ) {
    while( len-- ) {
        if( *num1 == *num2 ) {
            num1++;
            num2++;
        } else {
            return 0;
        }
    }
    return 1;
}

int findSeq( int numArray[], int sequence[], int seqLen, int numArrLen ) {
    for( int i = 0; i < numArrLen; i++ ) {
        if( compare( numArray, sequence, seqLen ) ) {
            return 1;
        }
        numArray++;
    }
    return 0;
}


int main( void ) {
    int * numArray = NULL, *sequence = NULL, *tmp = NULL;
    int err, cap = 10;

    numArray = (int*)malloc( cap * sizeof(int) );
    if( numArray == NULL ) {
        printf( "Failed to allocate memory.\n" );
        return 1;
    }
    printf( "Enter numbers:\n" );
    int cnt = 0;
    while( (err = readInput( &numArray[cnt] )) == 1 ) {
        cnt++;
        if( cnt + 1 > cap ) {
            cap *= 2;
            tmp = (int*)realloc( numArray, cap * sizeof(int) );
            if( !tmp ) {
                printf( "Failed to allocate memory.\n" );
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
    
    clearerr( stdin );                                                          

    printf( "Enter how many numbers you want to be in a sequence.\n" );
    if( readInput( &cap ) ) {
        sequence = (int*)malloc( cap * sizeof(int) );
        if( !sequence ) {
            printf( "Failed to allocate memory.\n" );
            free( numArray );
            return 1;
        }
        if( cap > cnt ) {
            printf( "The number count you seek exceed the number count in an array.\n" );
            free( numArray );
            return 1;
        }
        if( cap < 1 ) {
            printf( "The number of numbers must be 1 or higher.\n" );
            free( numArray );
            return 1;
        }
    } else {
        printf( "Invalid input.\n" );
        free( numArray );
        return 1;
    }

    printf( "Enter seeked number sequence:\n" );
    for( int i = 0; i < cap; i++ ) {
        if( !readInput( &sequence[i] ) ) {
            printf( "Invalid input.\n" );
            free( numArray );
            free( sequence );
            return 1;
        }
    }

    if( findSeq( numArray, sequence, cap, cnt ) )
        printf( "Found the sequence.\n" );
    else
        printf( "Sequence not found.\n" );
    free( sequence );
    free( numArray );
    return 0;
}