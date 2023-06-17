#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int * data;
    size_t size;
    size_t capacity;
} myVector;



void initVector( myVector * vector, size_t capacity )
{
    vector->data = (int*)malloc( capacity * sizeof(int) );
    if( !vector->data )
    {
        printf( "Failed to allocate memory\n" );
        return;
    }
    vector->size = 0;
    vector->capacity = capacity;
}

int pushBack( myVector * vector, int number )
{
    if( vector->size >= vector->capacity )
    {
        vector->capacity *= 2;
        vector->data = (int*)realloc( vector->data, vector->capacity * sizeof(int) );
        // failed to reallocate memory
        if( !vector-> data )
        {
            printf( "Failed to reallocate memory\n" );
            return -1;
        }
    }
    vector->data[vector->size] = number;
    vector->size++;
    return 1;
}

int getElement( myVector vector, int index )
{
    return vector.data[index];
}

int popBack( myVector * vector )
{
    if( vector->size > 0 )
    {
        int res = vector->data[vector->size - 1];
        vector->size--;
        return res;
    } else {
        printf( "Nothing to pop back\n" );
    }
    // redo
    return -1;
}

int eraseElement( myVector * vector, size_t index ) {
    if( vector->size > 0 )
    {
        if( index < vector->size )
        {
            int res = vector->data[index];
            for( size_t i = index + 1; i <= vector->size; i++ )
                vector->data[i - 1] = vector->data[i];
            vector->size--;
            return res;
        }
        else        
            printf( "Index is out of bounds\n" );
    }
    else
        printf( "Nothing to erase\n" );
    return -1;
}

void printVector( myVector vector )
{
    for( size_t i = 0; i < vector.size; i++ )
    {
        if( i )
            printf( " %d", vector.data[i] );
        else
            printf( "%d", vector.data[i] );
    }
    printf( "\n" );
}


void freeVector( myVector * vector )
{
    free( vector->data );
}


int main( void )
{
    myVector vector;
    initVector( &vector, 10 );
    pushBack( &vector, 1 );
    pushBack( &vector, 2 );
    pushBack( &vector, 3 );
    pushBack( &vector, 4 );
    pushBack( &vector, 5 );
    printVector( vector );

    printf( "Element at 0th index: %d\n", getElement( vector, 0 ) );
    printf( "Popped: %d\n", popBack( &vector ) );
    printf( "Popped: %d\n", popBack( &vector ) );
    printf( "Popped: %d\n", popBack( &vector ) );
    printf( "Popped: %d\n", popBack( &vector ) );
    printf( "Popped: %d\n", popBack( &vector ) );
    printf( "Popped: %d\n", popBack( &vector ) );
    printVector( vector );

    pushBack( &vector, 7 );
    pushBack( &vector, 6 );
    pushBack( &vector, 5 );
    pushBack( &vector, 4 );
    pushBack( &vector, 3 );
    pushBack( &vector, 2 );
    pushBack( &vector, 1 );
    printVector( vector );

    printf( "Erasing item index 2: %d removed\n", eraseElement( &vector, 2 ) );
    printVector( vector );

    freeVector( &vector );

    return 0;
}