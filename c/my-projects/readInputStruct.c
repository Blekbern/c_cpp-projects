#include <stdio.h>
#include <string.h>

typedef struct {
    int x;
    int y;
    int z;
} Point;


int readInput( int * numbers ) {
    if( scanf( "%d", numbers ) != 1 ) {
        return 0;
    }
    return 1;
}

int readInputPoint( Point * point ) {
    if( scanf( "%d", &(point->x) ) != 1 ) {
        return 0;
    }
    return 1;
}

void printNum( int * numbers ) {
    for( int i = 0; i < 10; i++ ) {
        printf( "%d ", *(numbers+i) );
    }
    printf( "\n" );
}

int main( void ) {
//    int numbers[10];
    Point boint;
//    for( int i = 0; i < 10; i++ ) {
//        if( !readInput( &(*(numbers+i)) ) ) {
//            printf( "Invalid input.\n" );
//            return 1;
//        }
//    }
//    printNum( numbers );
    if( !readInputPoint( &boint ) ) {
        printf( "Nespravny vstup.\n" );
        return 1;
    }
    printf( "%d\n", boint.x );
    Point points[2];
    for( int i = 0; i < 2; i++ ) {
        if( !readInputPoint( &points[i] ) ) {
            printf( "Invalid input.\n" );
            return 1;
        }
    }
    for( int i = 0; i < 2; i++ ) {
        printf( "%d\n", points[i].x );
    }
    return 0;
}