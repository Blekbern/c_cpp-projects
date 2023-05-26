#include <iostream>
#include <cstring>
#include <vector>
using namespace std;


string tweakLetters( string s, vector<int> arr ) {
    string newString = s;
    for( uint i = 0; i < s.size(); i++ ) {
        if( s[i] <= 'z' && s[i] >= 'a' ) {
            if( s[i] + arr[i] > 'z' ) {
                newString[i] = s[i] - 26 + arr[i];
                continue;
            }
            if( s[i] + arr[i] < 'a' ) {
                newString[i] = s[i] + 26 + arr[i];
                continue;
            }
        }
        if( s[i] <= 'Z' && s[i] >= 'A' ) {
            if( s[i] + arr[i] > 'Z' ) {
                newString[i] = s[i] - 26 + arr[i];
                continue;
            }
            if( s[i] + arr[i] < 'A' ) {
                newString[i] = s[i] + 26 + arr[i];
                continue;
            }
        }
        newString[i] = s[i] + arr[i];
    }
    return newString;
}

int main( void ) {    
    string s;
    int num;
    vector<int> arr;
    cin >> s;
    for( uint i = 0; i < s.size(); i++ ) {
        cin >> num;
        arr.push_back( num );
    }
    cout << tweakLetters( s, arr ) << endl;

    return 0;
}