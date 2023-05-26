#include <iostream>
using namespace std;


int main( void ) {
    int a, b;

    cout << "1st number:" << endl;
    cin >> a;
    cout << "2nd number:" << endl;
    cin >> b;

    // a = 3
    // b = 10

    cout << "Before swap: a = " << a << " b = " << b << endl; 
    a = a + b; // a = 3 + 10 -> 13
    b = a - b; // b = 13 - 10 -> 3
    a = a - b; // a = 13 - 3 -> 10

    cout << "After swap: a = " << a << " b = " << b << endl;

    return 0;
}