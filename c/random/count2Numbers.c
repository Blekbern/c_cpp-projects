#include <stdio.h>
#include <stdlib.h>

int countNumbers( int arrayNum[], int seekedNum, int len ) {
    int countNums = 0;
    while( len-- ) {
        if( *arrayNum == seekedNum && *(++arrayNum) == seekedNum ) 
            countNums++;
        arrayNum++;
    }
    return countNums;
}

int main( void ) {
    int * arrayNum;
    int cap = 10, err;
    int seekedNum;

    arrayNum = (int*)malloc( cap * sizeof(int) );
    printf( "Enter numbers.\n" );
    int i = 0;
    while( (err = scanf( "%d", &arrayNum[i] )) == 1 ) {
        i++;
        if( i + 1 > cap ) {
            cap *= 2;
            arrayNum = (int*)realloc( arrayNum, cap * sizeof(int) );
            if( arrayNum == NULL ) {
                printf( "Failed to allocate memory.\n" );
                return 1;
            }
        }
    }
    if( err != EOF ) {
        printf( "Invalid input.\n" );
        free( arrayNum );
        return 1;
    }

    clearerr( stdin );
    printf( "Enter number you want to search for.\n" );
    if( scanf( "%d", &seekedNum ) != 1 ) {
        printf( "Invalid input.\n" );
        free( arrayNum );
        return 1;
    }
    printf( "The count of two number \"%d\" next to each other is %d.\n", seekedNum, countNumbers( arrayNum, seekedNum, i ) );
    free( arrayNum );
    return 0;
}