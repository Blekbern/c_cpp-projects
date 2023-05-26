#include <iostream>
#include <cstring>
#include <numeric>
#include <vector>
#include <cmath>
#include <climits>
using namespace std;




int main( void ) {
    string s = "lalaaallla";
    for( uint i = 0; i < s.size(); i++ ) {
        if( s[i] == 'a' ) {
            s[i] = 'b';
            continue;
        } else {
            continue;
        }
    }
    cout << s << endl;
    return 0;
}