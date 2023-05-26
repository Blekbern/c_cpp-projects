#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.1415926535897932384626433832795028841971693993751058209749445923078164062

int main( void ) {
    double 	a, b, c,
			k, l, m,
			max,
			a1, b1, k1, l1;
    char v1, v2, v3;

	/* ----------------- TROJUHELNIK #1 ----------------- */
    printf( "Trojuhelnik #1:\n" );
    if( scanf( " %c%c%c %lf %lf %lf", &v1, &v2, &v3, &a, &b, &c ) !=6 
            || a <= 0 || b <= 0 || c <= 0 
			|| !( ( v1 == 'S' && v2 == 'S' && v3 == 'S' )
			|| ( v1 == 'S' && v2 == 'U' && v3 == 'S' )
			|| ( v1 == 'U' && v2 == 'S' && v3 == 'U' ) ) ) {
			printf( "Nespravny vstup.\n" );
                return 1;
    }
	if( v1 == 'U' && v2 == 'S' && v3 == 'U' ) {
		if( a >= 180 || c >= 180 ) {
			printf( "Nespravny vstup.\n" );
			return 1;
		}
		if( a + c >= 180 ) {
			printf( "Vstup netvori trojuhelnik.\n" );
			return 1;
		}
		a1 = a;
		b1 = c;
		c = b;
		a = sin( a1 * ( PI / 180 ) ) * ( c / sin( ( 180 - ( a1 + b1 ) ) * ( PI / 180 ) ) );
		b = sin( b1 * ( PI / 180 ) ) * ( c / sin( ( 180 - ( a1 + b1 ) ) * ( PI / 180 ) ) );
	}
	if( v1 == 'S' && v2 == 'U' && v3 == 'S') {
		if( b >= 180 ) {
			printf( "Nespravny vstup.\n" );
			return 1;
		}
		a1 = b;	
		b = sqrt( pow( a, 2 ) + pow( c, 2 ) - (2 * a * c * cos( a1 * ( PI / 180 ) ) ) );
	}
	/* -------------------- SORTING -------------------- */ 
	if( a > c ) {
		max = a;
		a = c;
		c = max;
	}
	if( b > c ) {
	    max = b;
	    b = c;
	    c = max;
	}
    if( a > b ) {
	    max = a;
	    a = b;
		b = max;
	}
	/* -------------------- ------- -------------------- */
    if( a + b - c <= __DBL_EPSILON__ * 100 * a ) {
		printf( "Vstup netvori trojuhelnik.\n");
        return 1;
    	}
	/* -------------------- TROJUHELNIK #2 -------------------- */
	printf( "Trojuhelnik #2:\n" );
    if( scanf( " %c%c%c %lf %lf %lf", &v1, &v2, &v3, &k, &l, &m ) !=6 
            || k <= 0 || l <= 0 || m <= 0 
			|| !( ( v1 == 'S' && v2 == 'S' && v3 == 'S' )
			|| ( v1 == 'S' && v2 == 'U' && v3 == 'S' )
			|| ( v1 == 'U' && v2 == 'S' && v3 == 'U') ) ) {
			    printf( "Nespravny vstup.\n" );
                return 1;
	}
	if( v1 == 'U' && v2 == 'S' && v3 == 'U' ) {
		if( k >= 180 || m >= 180 ) {
			printf( "Nespravny vstup.\n" );
			return 1;
		}
		if( k + m >= 180 ) {
			printf( "Vstup netvori trojuhelnik.\n" );
			return 1;
		}
		k1 = k;
		l1 = m;
		m = l;
		k = sin( k1 * ( PI / 180 ) ) * ( m / sin( ( 180 - ( k1 + l1 ) ) * ( PI / 180 ) ) );
		l = sin( l1 * ( PI / 180 ) ) * ( m / sin( ( 180 - ( k1 + l1 ) ) * ( PI / 180 ) ) );
	}
	if( v1 == 'S' && v2 == 'U' && v3 == 'S' ) {
		if( l >= 180 ) {
			printf( "Nespravny vstup.\n" );
			return 1;
		}
		k1 = l;
		l = k;
		k = sqrt( pow( l, 2 ) + pow( m, 2 ) - ( 2 * l * m * cos( k1 * ( PI / 180 ) ) ) );
	}
	/* -------------------- SORTING -------------------- */
	if( k > m ) {
		max = k;
		k = m;
		m = max;
	}
	if( l > m ) {
		max = l;
		l = m;
		m = max;
	}
	if( k > l ) {
		max = k;
		k = l;
		l = max;
	}
	/* -------------------- ------- -------------------- */
	if( k + l - m <= __DBL_EPSILON__ * 100 * m ) {
		printf( "Vstup netvori trojuhelnik.\n");
		return 1;
	}
	if( fabs( c - m ) <= __DBL_EPSILON__ * c * 1000 &&
		fabs( b - l ) <= __DBL_EPSILON__ * b * 1000 &&
		fabs( a - k ) <= __DBL_EPSILON__ * a * 1000 ) {
		printf( "Trojuhelniky jsou shodne.\n" );
		return 0;	
	}
	if( fabs( c / m - b / l ) <= __DBL_EPSILON__ * 1000 * ( c / m ) &&
		fabs( b / l - a / k ) <= __DBL_EPSILON__ * 1000 * ( b / l ) ) {
		printf( "Trojuhelniky nejsou shodne, ale jsou podobne.\n");
		return 0;
	}
	else {
		printf( "Trojuhelniky nejsou shodne ani podobne.\n");
		return 0;
	}
	return 0;	
}