#include <iostream>
using namespace std;

class complexNum {
    private:
        int m_R;
        int m_Im;
    public:
        complexNum() {}
        complexNum( int r, int im ) {
            m_R = r;
            m_Im = im;
        }

        void printComplex() {
            cout << m_R << " + " << m_Im << "i" << endl;
        }
        
        complexNum operator + ( const complexNum &n2 ) {    // passing a reference (alias) -> doesnt create copy
            complexNum res;                                 // to be sure to not make any changes we const it :)
            res.m_R = m_R + n2.m_R;
            res.m_Im = m_Im + n2.m_Im;
            return res;
        }

        friend void printCNum( complexNum n );              // get acces to private members via function
};

void printCNum( complexNum n ) {
    cout << n.m_R << " + " << "i" << n.m_Im << endl;
}


int main( void ) {
    complexNum n1( 3, 4 );
    complexNum n2( 2, 2 );
    complexNum n3 = n1 + n2;
    printCNum( n3 );
    // n3.printComplex();

    return 0;
}