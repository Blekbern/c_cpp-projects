#include <stdio.h>
#include <stdlib.h>


// ------------------- UPGRADE ------------------- 
//  -> TRY 3 NUMBERS?
//  -> IDK?
// -----------------------------------------------



/*  --------------------------NEED TO FIGURE OUT THE LOCAL VARIABLE STUFF >:( --------------------------

int readInput( int numArray[], int * cnt, int * cap ) {
    int err;
    int * tmp = NULL;
    while( (err = scanf( "%d", &numArray[*cnt] )) == 1 ) {
        (*cnt)++;
        if( *cnt + 1 > *cap ) {
            *cap *= 2;
            tmp = (int*)realloc( numArray, *cap * sizeof(int) );
            if( !tmp ) {
                printf( "Failed to reallocate memory.\n" );
                free( numArray );
                return 0;
            }
            numArray = tmp;
        }
    }
    if( err != EOF ) {
        printf( "Invalid input.\n" );
        return 0;
    }
    return 1;
}

    ----------------------------------------------------------------------------------------------------
*/

int searchNumbers( int numArray[], int cnt, int sumNum ) {
    int totalNumbers = 0;
    for( int i = 0; i < cnt - 1; i++ ) {
        for( int j = i + 1; j < cnt; j++ ) {
            if( (numArray[i] + numArray[j]) == sumNum ) {
                totalNumbers++;
                printf( "%d (index: %d) + %d (index: %d)\n", numArray[i], i, numArray[j], j );
            }
        }
    }
    return totalNumbers;
}

int main( void ) {
    int * numArray = NULL, *tmp = NULL;
    int cnt = 0, cap = 10, sumNum;
    int err;

    numArray = (int*)malloc( cap * sizeof(int) );
    if( !numArray ) {
        printf( "Failed to allocate memory.\n" );
        return 1;
    }
    printf( "Fill the array with numbers.\n" );

/*  if( !readInput( numArray, &cnt, &cap ) )
 *      return 1;
*/

// vvvvvvvvvvvvvvvvvvvvvv      THIS PART PUT IN FUNCTION      vvvvvvvvvvvvvvvvvvvvvv


    while( (err = scanf( "%d", &numArray[cnt] )) == 1 ) {
        cnt++;
        if( cnt + 1 > cap ) {
            cap *= 2;
            tmp = (int*)realloc( numArray, cap * sizeof(int) );
            if( !tmp ) {
                printf( "Failed to reallocate memory.\n" );
                free( numArray );
                return 0;
            }
            numArray = tmp;
        }
    }
    if( err != EOF ) {
        printf( "Invalid input.\n" );
        return 0;
    }

// -----------------------------------------------------------------------------------

    clearerr( stdin );

    printf( "Enter the sum you want to search for.\n" );
    if( scanf( "%d", &sumNum ) != 1 ) {
        printf( "Invalid input.\n" );
        return 1;
    }
    printf( "Total combinations: %d\n", searchNumbers( numArray, cnt, sumNum ) );

    free( numArray );
    return 0;
}