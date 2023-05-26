#include <stdio.h>
#include <stdlib.h>
#include <math.h>



int main( void ) {
	double 	a, b, c,
			k, l, m,
			max;
	
		printf( "Trojuhelnik #1:\n" );
		if( scanf( "%lf %lf %lf", &a, &b, &c ) != 3
				|| a <= 0 || b <= 0 || c <= 0 ) {
			printf( "Nespravny vstup.\n" );
			return 1;
		}
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
		if( a + b - c <= __DBL_EPSILON__ * 100 * a ) {
			printf( "Strany netvori trojuhelnik.\n" );
			return 1;
		}


		printf( "Trojuhelnik #2:\n" );
		if( scanf( "%lf %lf %lf", &k, &l, &m ) != 3
				|| k <= 0 || l <= 0 || m <= 0 ) {
			printf( "Nespravny vstup.\n" );
			return 1;
		}
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
		if( k + l - m <= __DBL_EPSILON__ * 100 * k  ) {
			printf( "Strany netvori trojuhelnik.\n" );
			return 1;
		}


		if( c == m && b == l && a == k) {
			printf("Trojuhelniky jsou shodne.\n");
			return 0;	
		}

		if( fabs( c / m - b / l ) <= __DBL_EPSILON__ * 5000 * ( c / m ) &&
			fabs( b / l - a / k ) <= __DBL_EPSILON__ * 5000 * ( b / l ) ) {
			printf( "Trojuhelniky nejsou shodne, ale jsou podobne.\n" );
			return 0;
		}
		else {
			printf( "Trojuhelniky nejsou shodne ani podobne.\n" );
			return 0;
		}
return 0;
}
