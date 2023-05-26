#include <iostream>
using namespace std;


class fraction {
    private: 
        int m_Numerator;
        int m_Denominator;
    public:
        fraction( int numerator, int denominator ) {
            m_Numerator = numerator;
            if( denominator == 0 ) {
                cout << "Fraction is NaN" << endl;
                exit( 1 );
            }
            m_Denominator = denominator;
        }

        fraction() {}

        fraction fractionAdd( fraction fr2 ) {
            int n, d;
            if( m_Denominator == fr2.m_Denominator )
                m_Numerator += fr2.m_Denominator;
            n = m_Numerator * fr2.m_Denominator + fr2.m_Numerator * m_Denominator;
            d = m_Denominator * fr2.m_Denominator;
            return fraction( n, d );
        }

        fraction fractionSub( fraction fr2 ) {
            int n, d;
            if( m_Denominator == fr2.m_Denominator )
                m_Numerator -= fr2.m_Denominator;
            n = m_Numerator * fr2.m_Denominator - fr2.m_Numerator * m_Denominator;
            d = m_Denominator * fr2.m_Denominator;
            return fraction( n, d );
        }

        fraction fractionMul( fraction fr2 ) {
            int n, d;
            n = m_Numerator * fr2.m_Numerator;
            d = m_Denominator * fr2.m_Denominator;
            return fraction( n, d );
        }

        void printFraction() {
            cout << "(" << m_Numerator << " / " << m_Denominator << ")" << endl;
        }
};




int main( void ) {
    int nominator,      nominator2,
        denominator,    denominator2;
    
    fraction fr1();
    fraction fr2();


    cout << "Enter first fraction:" << endl;
    if( !(cin >> nominator >> line >> denominator) && line != "/" ) {
        cout << "Invalid input." << endl;
        return 1;
    }

    return 0;
}