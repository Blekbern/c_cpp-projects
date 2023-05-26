#include <stdio.h>

int squareFree( int k ) {
    int num = 1, seq = 0;
    
    while( true ) {
        int isSquareFree = 1;
        
        for( int toCheck = 2; toCheck * toCheck <= num; toCheck++ ) {       // overovani zda-li neobsahuje 2 mocninu kterehokoliv cisla
            if( (num % (toCheck * toCheck)) == 0 ) {                        // pokud obsahuje (cislo % overovaneCislo == 0)
                isSquareFree = 0;                                           // potom neni square free (nastav isSquareFree na 0)
                break;                                                      // bez pryc z cyklu a jdi na dalsi cislo
            }
        }
        
        if( isSquareFree ) {                                                // pokud je cislo square free zvys poradi
            seq++;                                                          // pokud je poradi == k potom vrat square free cislo
            if( seq == k ) {
                return num;
            }
        }
        num++;
    }
}


int main( void ) {
    int k, err;

    printf( "Poradi:\n" );
    while( (err = scanf( "%d", &k )) == 1 ) {
        if( k <= 0 ) {
            printf( "Nespravny vstup.\n" );
            return 1;
        }
        printf( "= %d\n", squareFree( k ) );
    }
    if( err != EOF ) {
        printf( "Nespravny vstup.\n" );
        return 1;    
    }
    return 0;
}