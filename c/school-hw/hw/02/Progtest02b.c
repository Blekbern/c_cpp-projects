#include <stdio.h>

char cisloZ( int cislo ) {
    if( cislo >= 0 && cislo <= 9 ) {
        cislo += '0';
    }
    else {
        if( cislo > 9 ) {
            cislo += 'a' - 10;
        }
    }
    return cislo;
}


int print( int R, int cislo ) {
    int rad = 1;
    while( rad <= cislo ) {
        rad *= R;
    }
    printf( "%d = ", cislo );
    if( cislo == 0 ) {
        printf( "0" );
    }
    else {
        while( rad > 1 ) {
            rad /= R;
            printf( "%c", cisloZ ( cislo / rad ) );
            cislo %= rad;
        }
    }
    printf( " (%d)\n", R );
    return 0;
}

int sym( int R, int cislo ) {
    int cislo2 = cislo;
    int rad = 1;
    while( rad <= cislo ) {
        rad *= R;
    }
    while( rad > 1 ) {
        rad /= R;
        if( cislo / rad == cislo2 % R ) {
            cislo %= rad;
            cislo2 /= R;
        }
        else {
            return 0;
        }
    }
    return 1;
}


int main() {
    long long int R, LO, HI, i, sum;
    char X;
    printf( "Vstupni intervaly:\n" );
    while( scanf( " %c", &X ) != EOF ) {
        if( scanf( "%lld %lld %lld", &R, &LO, &HI ) != 3 || R < 2 || R > 36 || LO > HI || LO < 0 || HI < 0 ) {
            printf( "Nespravny vstup.\n" );
            return 0;
        }
        if( !( X == 'l' || X == 'c') ) {
            printf( "Nespravny vstup.\n" );
            return 1;
        }
        if( X == 'l' ) {
            for( i = LO; i <= HI; i++ ) {
                if( sym( R, i ) == 1 ) {
                    print( R, i );
                }
            }
        }
        if( X == 'c' ) {
            sum = 0;
            for( i = LO; i <= HI; i++ ) {
                if( sym( R, i ) == 1 ) {
                    sum++;
                }
            }
            printf( "Celkem: %lld\n", sum );
        }

    }
    return 0;
}