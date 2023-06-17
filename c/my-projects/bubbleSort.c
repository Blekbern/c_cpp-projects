#include <stdio.h>
#include <random>
#include <time.h>

void bubbleSort_v1( int arr[], int length )
{
    for( int i = 0; i < length; i++ )
    {
        for( int j = 0; j < length - 1; j++ )
        {
            if( arr[j + 1] < arr[j] )
            {
                int tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }
}


void bubbleSort_v2( int arr[], int length )
{
    int swap;
    for( int i = 0; i < length; i++ )
    {
        swap = 0;
        for( int j = 0; j < length - 1; j++ )
        {
            if( arr[j + 1] < arr[j] )
            {
                int tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
                swap = 1;
            }
        }
        if( !swap )
            return;
    }
}


void bubbleSort_v3( int arr[], int length )
{
    int swap;
    int index = length - 1;
    int iLastSwap;

    for( int i = 0; i < length; i++ )
    {
        swap = 0;
        for( int j = 0; j < index; j++ )
        {
            if( arr[j + 1] < arr[j] )
            {
                int tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
                swap = 1;
                iLastSwap = j + 1;
            }
        }
        if( !swap )
            return;
        index = iLastSwap;
    }
}


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


int main( void )
{
    srand( time(NULL) );
    int numbers[10];
    int length = sizeof( numbers ) / sizeof( numbers[0] );
    
    // int arr1[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    // int arr2[10] = { 10, 9, 8, 7, 6 , 5, 4, 3, 2, 1 };

    for( int i = 0; i < length; i++ )
        numbers[i] = rand() % 100;
    
    printNumbers  ( numbers, length );
    bubbleSort_v3 ( numbers, length );
    printNumbers  ( numbers, length );
}