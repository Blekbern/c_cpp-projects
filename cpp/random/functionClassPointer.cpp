#include <iostream>
using namespace std;

class TPoint {
    public:
        int m_X;
        int m_Y;
};


// BY REFERENCE
bool readClassInput( TPoint & point ) {
    if( !(cin >> point.m_X) || point.m_X <= 0 ) {
        cout << "Failed to read input." << endl;
        return false;
    }
    return true;
}

// BY POINTER
bool readClassInput( TPoint * point ) {
    if( !(cin >> point -> m_X) || point -> m_X <= 0 ) {
        cout << "Failed to read input." << endl;
        return false;
    }
    return true;
}



int main( void ) {
    TPoint point;
    if( !readClassInput( point ) )
        return 1;
    cout << point.m_X << endl;
    return 0;
}