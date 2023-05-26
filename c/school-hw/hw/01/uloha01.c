#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.1415926535897932384626433832795028841971693993751058209749445923078164062 


double distance( double x1, double y1,
                 double x2, double y2 ) {
    return sqrt( pow( x1 - x2, 2 ) + pow( y1 - y2, 2 ) );
}

int cmp( double num1, double num2 ) {
    return fabs( fabs( num1 ) - fabs( num2 ) ) < fabs( __DBL_EPSILON__ * 10000 * num1 );
}

double areaOverlay( double r1, double r2, double dist ) {
    double tmp1, tmp2, tmp3;
    tmp1 = acos( ((dist * dist) + (r1 * r1) - (r2 * r2)) / (2 * dist * r1) );
    tmp2 = acos( ((dist * dist) + (r2 * r2) - (r1 * r1)) / (2 * dist * r2) );
    tmp3 = sqrt( (-dist + r1 + r2) * (dist + r1 - r2) * (dist - r1 + r2) * (dist + r1 + r2));
    return (r1 * r1 * tmp1) + (r2 * r2 * tmp2) - (tmp3 / 2);
}

int main( void ) {
    double  x1, y1, r1,
            x2, y2, r2;

    printf( "Zadejte parametry kruznice #1:\n" );
    if( scanf( "%lf %lf %lf", &x1, &y1, &r1 ) != 3 || r1 <= 0 ) {
        printf( "Nespravny vstup.\n" );
        return 1;
    }
    
    printf( "Zadejte parametry kruznice #2:\n" );
    if( scanf( "%lf %lf %lf", &x2, &y2, &r2 ) != 3 || r2 <= 0 ) {
        printf( "Nespravny vstup.\n" );
        return 1;
    }



    if( distance( x1, y1, x2, y2 ) + r2 < r1 ) {
        printf( "Kruznice #2 lezi uvnitr kruznice #1, prekryv: %lf\n", (PI * r2 * r2) );
        return 0;
    }

    if( distance( x1, y1, x2, y2 ) + r1 < r2 ) {
        printf( "Kruznice #1 lezi uvnitr kruznice #2, prekryv: %lf\n", (PI * r1 * r1) );
        return 0;
    }



    if( cmp( x1, x2 ) && cmp( y1, y2 ) && cmp( r1, r2 ) ) {
        printf( "Kruznice splyvaji, prekryv: %lf\n", (PI * r1 * r1) );
        return 0;
    }

    if( cmp( distance( x1, y1, x2, y2 ) + r2, r1 ) ) {
        printf( "Vnitrni dotyk, kruznice #2 lezi uvnitr kruznice #1, prekryv: %lf\n", (PI * r2 * r2) );
        return 0;
    }

    if( cmp( distance( x1, y1, x2, y2 ) + r1, r2 ) ) {
        printf( "Vnitrni dotyk, kruznice #1 lezi uvnitr kruznice #2, prekryv: %lf\n", (PI * r1 * r1) );
        return 0;
    }

    if( cmp( distance( x1, y1, x2, y2 ), (r1 + r2) ) ) {
        printf( "Vnejsi dotyk, zadny prekryv.\n" );
        return 0;
    }

    if( distance( x1, y1, x2, y2 ) > (r1 + r2) ) {
        printf( "Kruznice lezi vne sebe, zadny prekryv.\n" );
        return 0;
    }

    if( distance( x1, y1, x2, y2 ) < (r1 + r2) ) {
        printf( "Kruznice se protinaji, prekryv: %lf\n", areaOverlay( r1, r2, distance( x1, y1, x2, y2 ) ) );
        return 0;
    }

    return 0;
}