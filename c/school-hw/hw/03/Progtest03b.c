#ifndef __PROGTEST__
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <float.h>
#include <assert.h>
#endif /* __PROGTEST__ */

/* ----------------------------------------------------------------------------------------------------------------------- */

int clipping( double p[], double q[], double * tMin, double * tMax ) {
  double t1 = 0, t2 = 1;
  for( int i = 0; i < 4; i++ ) {
      if( p[i] == 0 && q[i] < 0 ) {
        return 0;
      }
      if( p[i] < 0 ) {
        if( q[i] / p[i] > t1 ) {
          t1 = q[i] / p[i];
        }
      }
      else {
        if( p[i] > 0 ) {
          if( q[i] / p[i] < t2 ) {
            t2 = q[i] / p[i];
          }
        }
      }
    }
  if( t1 > t2 ) {
    if( fabs( t1 - t2 ) <= __DBL_EPSILON__ * 1000 * t1 * t2 ) {
        *tMin = t1;
        *tMax = t2;
        return 1;
    }
      return 0;
  }
  *tMin = 0;
  *tMax = t2;
  return 1;
}

/* ----------------------------------------------------------------------------------------------------------------------- */


int                clipLine                                ( double            rx1,
                                                             double            ry1,
                                                             double            rx2,
                                                             double            ry2,
                                                             double          * ax,
                                                             double          * ay,
                                                             double          * bx,
                                                             double          * by )
{
    double xMin, yMin, xMax, yMax, p[4], q[4], t1 = 0, t2 = 1;
    double xL1, yL1, xL2, yL2;
    if( rx1 > rx2 ) {
      xMax = rx1;
      xMin = rx2;
    }
    else {
      xMax = rx2;
      xMin = rx1;
    }
    if( ry1 > ry2 ) {
      yMax = ry1;
      yMin = ry2;
    }
    else {
      yMax = ry2;
      yMin = ry1;
    }
    p[0] = -( *bx - *ax );
    p[1] = *bx - *ax;
    p[2] = -( *by - *ay );
    p[3] = *by - *ay;
    
    q[0] = *ax - xMin;
    q[1] = xMax - *ax;
    q[2] = *ay - yMin;
    q[3] = yMax - *ay;

    if( clipping( p, q, &t1, &t2 ) == 1 ) {
      xL1 = *ax + t1 * ( *bx - *ax );
      yL1 = *ay + t1 * ( *by - *ay );
      xL2 = *ax + t2 * ( *bx - *ax );
      yL2 = *ay + t2 * ( *by - *ay );
      *ax = xL1;
      *ay = yL1;
      *bx = xL2;
      *by = yL2;
      return 1;
    }
    else {
      return 0;
    }
}

/* ----------------------------------------------------------------------------------------------------------------------- */

#ifndef __PROGTEST__
int                almostEqual                             ( double            x,
                                                             double            y )
{
  if( fabs( y - x ) <= __DBL_EPSILON__ * 1000 * y * x ) {
    return 1;
  }
  else {
    return 0;
  }
}

/* ----------------------------------------------------------------------------------------------------------------------- */

int                main                                    ( void )
{
  double x1, y1, x2, y2;

  x1 = 60;
  y1 = 40;
  x2 = 70;
  y2 = 50;
  assert ( clipLine ( 10, 20, 90, 100, &x1, &y1, &x2, &y2 )
           && almostEqual ( x1, 60 )
           && almostEqual ( y1, 40 )
           && almostEqual ( x2, 70 )
           && almostEqual ( y2, 50 ) );

  x1 = 0;
  y1 = 50;
  x2 = 20;
  y2 = 30;
  assert ( clipLine ( 90, 100, 10, 20, &x1, &y1, &x2, &y2 )
           && almostEqual ( x1, 10 )
           && almostEqual ( y1, 40 )
           && almostEqual ( x2, 20 )
           && almostEqual ( y2, 30 ) );

  x1 = 0;
  y1 = 30;
  x2 = 120;
  y2 = 150;
  assert ( clipLine ( 10, 20, 90, 100, &x1, &y1, &x2, &y2 )
           && almostEqual ( x1, 10 )
           && almostEqual ( y1, 40 )
           && almostEqual ( x2, 70 )
           && almostEqual ( y2, 100 ) );

  x1 = -10;
  y1 = -10;
  x2 = -20;
  y2 = -20;
  assert ( ! clipLine ( 10, 20, 90, 100, &x1, &y1, &x2, &y2 ) );

  x1 = 0;
  y1 = 30;
  x2 = 20;
  y2 = 10;
  assert ( clipLine ( 10, 20, 90, 100, &x1, &y1, &x2, &y2 )
           && almostEqual ( x1, 10 )
           && almostEqual ( y1, 20 )
           && almostEqual ( x2, 10 )
           && almostEqual ( y2, 20 ) );

  x1 = 0;
  y1 = 0.3553;
  x2 = 10.45;
  y2 = 0;
  assert ( clipLine ( 0.95, 0.323, 1, 1, &x1, &y1, &x2, &y2 ) 
           && almostEqual ( x1, 0.95 )
           && almostEqual ( y1, 0.323 )
           && almostEqual ( x2, 0.95 )
           && almostEqual ( y2, 0.323 ) );
  return 0;
}
#endif /* __PROGTEST__ */