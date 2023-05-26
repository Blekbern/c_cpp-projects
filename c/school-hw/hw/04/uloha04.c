#include <stdio.h>
#include <stdlib.h>

#define MAX 10000


int cmpSort( const int * a, const int * b ) {
    return (*a > *b) - (*b > *a);
}

int readInput( int array[], int * cnt ) {
    int err;
    printf( "Delky nosniku:\n" );
    while( (err = scanf( "%d", &array[*cnt] )) == 1 ) {
        if( array[*cnt] < 1 || *cnt > (MAX - 1) ) {
            printf( "Nespravny vstup.\n" );
            return 0;
        }
        *cnt += 1;
    }
    if( err != EOF || *cnt < 3 ) {
        printf( "Nespravny vstup.\n" );
        return 0;
    }
    return 1;
}

int triangles( int array[], int cnt ) {
    int numTriang = 0;
    for( int i = 0; i < cnt - 2; i++ ) {
        if( i > 0 && array[i] == array[i - 1] ) {
            continue;
        }
        for( int j = i + 1; j < cnt - 1; j++ ) {
            if(  j > i + 1 && array[j] == array[j - 1] ) {
                continue;
            }
            for( int k = j + 1; k < cnt; k++ ) {
                if( k > j + 1 && array[k] == array[k - 1] ) {
                    continue;
                }
                else {
                    if( array[i] + array[j] > array[k]
                        && array[j] + array[k] > array[i]
                        && array[i] + array[k] > array[j] ) {
                        numTriang++;
                    }
                }
            }
        }
    }
    return numTriang;
}

int main( void ) {
    int array[MAX];
    int cnt = 0;
    if( !readInput( array, &cnt ) )
        return 1;
    qsort( array, cnt, sizeof(*array), (int(*)(const void*, const void*))cmpSort );
    printf( "Trojuhelniku: %d\n", triangles( array, cnt ) );

    return 0;
}