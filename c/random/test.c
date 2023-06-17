#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main( void ) {
    char * myString = NULL;
    size_t buffSize;
    getline( &myString, &buffSize, stdin );
    while( *myString ) {
        printf( "%c", *myString++ );
    }
    printf( "\n" );
    return 0;
}