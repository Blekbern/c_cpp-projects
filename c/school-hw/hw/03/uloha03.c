#ifndef __PROGTEST__
#include <stdio.h>
#include <assert.h>
#endif /* __PROGTEST__ */

int leapYear( int y ) {
	if( (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0) )
		  return 1;
    else
    	return 0;
}

void ifLeapYear( int y, int monthDays[] ) {
  if( leapYear( y ) )
    monthDays[1] = 29;
  else
    monthDays[1] = 28;
}


long long int daysDiff( int y1, int m1, int d1,
              			int y2, int m2, int d2 )
{
	long long int cnt = 0;
  int monthIndex = m1;
  int monthDays[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if( y1 != y2 ) {
		for( int i = y1; i < y2; i++ ) {
			ifLeapYear( i, monthDays );
			while( monthIndex <= 12 ) {
				cnt += monthDays[monthIndex - 1];
				monthIndex++;
				if( monthIndex > 12 ) {
					monthIndex = 1;
					break;
				}
			}
		}
		ifLeapYear( y2, monthDays );
		for( int i = 1; i < m2; i++ ) {
			cnt += monthDays[i - 1];
		}
	}
	else {
		if( y1 == y2 && m1 == m2 ) {
      ifLeapYear( y2, monthDays );
			cnt += d2 - d1;
			return cnt;
		}
		else {
			if( y1 == y2 && m1 != m2 ) {
        ifLeapYear( y2, monthDays );
				for( int i = m1; i < m2; i++ ) {
					cnt += monthDays[i - 1];
				}
			}
		}
	}
  cnt += d2 - d1;
  return cnt;
}

long long int cuckooTime( int h1, int i1,
                		  int h2, int i2, int * days )
{
  long long int cnt = 0;
  if( h1 > h2 ) {
    h1 -= 12;
    h2 += 12;
    *days -= 1;
  }

  if( *days == 0 && h1 == h2 && i1 == 0 && i2 == 0 ) {
    cnt += h1;
    return cnt;
  }
if( *days == 0 && h1 == 0 && i1 == 0 && h2 == 0 ) {
  cnt += 12;
  if( i2 >= 30 ) {
    cnt++;
  }
  return cnt;
}
  while( h1 != h2 ) {
    if( i1 == 60 ) {
      i1 = 0;
      h1++;
    }
    if( i1 == 0 ) {
      if( h1 > 12 ) {
        cnt += h1 - 12;
      }
      else {
        if( h1 == 0 )
          cnt += 12;
        cnt += h1;
      }      
    }
    if( i1 == 30 ) {
      cnt++;
    }
    i1++;
  }
  if( i2 >= 30 ) {
    cnt++;
  }

  return cnt;
}

int validDate(  int y1, int m1, int d1, int h1, int i1,
                int y2, int m2, int d2, int h2, int i2 )
{
  if( y1 < 1600 || m1 < 1 || m1 > 12 || d1 < 1 || d1 > 31 || h1 < 0 || h1 > 23 || i1 < 0 || i1 > 59 ||
      y2 < 1600 || m2 < 1 || m2 > 12 || d2 < 1 || d2 > 31 || h2 < 0 || h2 > 23 || i2 < 0 || i2 > 59 )
      return 0;
  if( y1 == y2 && m1 > m2 ) return 0;
  if( y1 == y2 && m1 == m2 && d1 > d2 ) return 0;
  if( y1 == y2 && m1 == m2 && d1 == d2 && h1 > h2 ) return 0;
  if( y1 == y2 && m1 == m2 && d1 == d2 && h1 == h2 && i1 > i2 ) return 0;
  if( leapYear( y1 ) && m1 == 2 && d1 > 29 ) return 0;
  if( !leapYear( y1 ) && m1 == 2 && d1 > 28 ) return 0;
  if( leapYear( y2 ) && m2 == 2 && d2 > 29 ) return 0;
  if( !leapYear( y2 ) && m2 == 2 && d2 > 28 ) return 0;

  return 1;
}

int cuckooClock ( int y1, int m1, int d1, int h1, int i1,
                  int y2, int m2, int d2, int h2, int i2, long long int * cuckoo )
{
  int days, time; 
  if( !validDate( y1, m1, d1, h1, i1, y2, m2, d2, h2, i2 ) ) return 0;
  days = daysDiff( y1, m1, d1, y2, m2, d2 );
  time = cuckooTime( h1, i1, h2, i2, &days );
  *cuckoo = days * 180 + time; 
  return 1;
}


#ifndef __PROGTEST__
int main ( int argc, char * argv [] )
{
  long long int cuckoo;

  assert ( cuckooClock ( 2020, 10,  1, 13, 15,
                         2020, 10,  1, 18, 45, &cuckoo ) == 1 && cuckoo == 26 );
  assert ( cuckooClock ( 2020, 10,  1, 13, 15,
                         2020, 10,  2, 11, 20, &cuckoo ) == 1 && cuckoo == 165 );
  assert ( cuckooClock ( 2020,  1,  1, 13, 15,
                         2020, 10,  5, 11, 20, &cuckoo ) == 1 && cuckoo == 50025 );
  assert ( cuckooClock ( 2019,  1,  1, 13, 15,
                         2019, 10,  5, 11, 20, &cuckoo ) == 1 && cuckoo == 49845 );
  assert ( cuckooClock ( 1900,  1,  1, 13, 15,
                         1900, 10,  5, 11, 20, &cuckoo ) == 1 && cuckoo == 49845 );
  assert ( cuckooClock ( 2020, 10,  1,  0,  0,
                         2020, 10,  1, 12,  0, &cuckoo ) == 1 && cuckoo == 102 );
  assert ( cuckooClock ( 2020, 10,  1,  0, 15,
                         2020, 10,  1,  0, 25, &cuckoo ) == 1 && cuckoo == 0 );
  assert ( cuckooClock ( 2020, 10,  1, 12,  0,
                         2020, 10,  1, 12,  0, &cuckoo ) == 1 && cuckoo == 12 );
  assert ( cuckooClock ( 2020, 11,  1, 12,  0,
                         2020, 10,  1, 12,  0, &cuckoo ) == 0 );
  assert ( cuckooClock ( 2020, 10, 32, 12,  0,
                         2020, 11, 10, 12,  0, &cuckoo ) == 0 );
  assert ( cuckooClock ( 2100,  2, 29, 12,  0,
                         2100,  2, 29, 12,  0, &cuckoo ) == 0 );
  assert ( cuckooClock ( 2400,  2, 29, 12,  0,
                         2400,  2, 29, 12,  0, &cuckoo ) == 1 && cuckoo == 12 );
  return 0;
}
#endif /* __PROGTEST__ */
