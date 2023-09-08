#include <stdio.h>
#include <stdlib.h>
#include <time.h>



void printNumbers( int numbers[], int length )
{
    for( int i = 0; i < length; i++ )
    {
        if( i )
            printf( " " );
        printf( "%d", numbers[i] );
    }
    printf( "\n" );
}

void mergeSort( int numbers[], int start, int end )
{
    if( start == end )
        return;
    int mid = (end - start + 1) / 2;
    int * leftArr = (int*)malloc( mid * sizeof(int) );
    int * rightArr = (int*)malloc( (end + 1 - mid) * sizeof(int) );

    for( int i = 0; i < mid; i++ )
        leftArr[i] = numbers[i];

    for( int i = 0; i < (end + 1 - mid); i++ )
        rightArr[i] = numbers[i + mid];

    // printf( "Left: " );
    // printNumbers( leftArr, mid );
    // printf( "Right: " );
    // printNumbers( rightArr, end + 1 - mid );

    mergeSort( leftArr, 0, mid - 1 );
    mergeSort( rightArr, 0, end - mid );

    int p1 = 0, p2 = 0;
    int currInd = 0;
    while( p1 < mid && p2 < end + 1 - mid )
    {
        if( leftArr[p1] < rightArr[p2] )
            numbers[currInd++] = leftArr[p1++];
        else
            numbers[currInd++] = rightArr[p2++];
    }

    if( p1 < mid )
    {
        for( int i = p1; i < mid; i++ )
            numbers[currInd++] = leftArr[p1++];
    }

    if( p2 < end + 1 - mid )
    {
        for( int i = p2; i < end + 1 - mid; i++ )
            numbers[currInd++] = rightArr[p2++];
    }

    free( leftArr );
    free( rightArr );
}


int main( void )
{
    srand( time(NULL) );
    int numbers[10];
    int length = sizeof( numbers ) / sizeof( numbers[0] );
    for( int i = 0; i < length; i++ )
        numbers[i] = rand() % 100;
    printNumbers( numbers, length );

    mergeSort( numbers, 0, length - 1 );

    printNumbers( numbers, length );
    return 0;
}