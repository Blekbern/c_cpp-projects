#include <stdio.h>
#include <stdlib.h>


int main( void ) {
    int * numArray, num1, num2;
    int cap = 10, err, i = 0, cnt1 = 0, cnt2 = 0;
    numArray = (int*)malloc( cap * sizeof(int) );
    printf( "Enter numbers.\n" );
    while( (err = scanf( "%d", &numArray[i] )) == 1  ) {
        i++;
        if( i + 1 > cap ) {
            cap *= 2;
            numArray = (int*)realloc( numArray, cap * sizeof(int) );
            if( numArray == NULL ) {
                printf( "Failed to allocate memory.\n" );
                free( numArray );
                return 1;
            }
        }

    }
    if( err != EOF ) {
        printf( "Invalid input.\n" );
        free( numArray );
        return 1;
    }

    clearerr( stdin );
    printf( "Enter two numbers you wish to count.\n" );
    if( scanf( "%d %d", &num1, &num2 ) != 2 ) {
        printf( "Invalid input.\n" );
        free( numArray );
        return 1;
    }

    while( i-- ) {
        if( numArray[i] == num1 ) {
            cnt1++;
        }
        if( numArray[i] == num2 ) {
            cnt2++;
        }
    }
    if( cnt2 > cnt1 ) {
        printf( "There is more %d's than %d's.\n", num2, num1 );
    } else {
        printf( "There is more %d's than %d's.\n", num1, num2 );
    }
    free( numArray );
    return 0;
}