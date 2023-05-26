#include <iostream>
#include <algorithm>
#include <iterator>
#include <climits>
#include <string>
using namespace std;

template <class T>
class myVector {
    private:
        T * m_Vect;
        size_t m_Cnt = 0;
        size_t m_Max = 10;
    public:
        myVector() {
            cout << "Constructor called.\n" << endl;
            m_Vect = new T[m_Max];
        }
        ~myVector() {
            cout << "Destructor called.\n" << endl;
            delete[] m_Vect;
        }

        /* ---------------------------------------------------------------------- */
        bool reallocVector() {
            m_Max *= 2;
            T * tmp = new T[m_Max];
            if( !tmp ) {
                cout << "Memory allocation failed.\n" << endl;
                delete[] tmp;
                return false;
            } else {
                cout << "Reallocating memory for vector" << endl;
                for( unsigned int i = 0; i < m_Cnt; i++ ) {
                    tmp[i] = m_Vect[i];
                }
                delete[] m_Vect;
                m_Vect = tmp;
            }
            return true;
        }
        /* ---------------------------------------------------------------------- */

        bool pushBack( T input ) {
            if( m_Cnt + 1 >= m_Max ) {
                if( !reallocVector() ) {
                    return false;
                }
            }
            m_Vect[m_Cnt] = input;
            m_Cnt++;
            return true;
        }

        bool popBack() {
            if( m_Cnt == 0 ) {
                return false;
            } else {
                m_Cnt--;
            }
            return true;
        }
    
        void printVector() {
            cout << "Printing vector ..." << endl;
            for( unsigned int i = 0; i < m_Cnt; i++ ) {
                if( i ) {
                    cout << " ";
                }
                cout << m_Vect[i];
            }
            cout << endl;
        }

        unsigned int sizeofVector() {
            return m_Cnt;
        }
};


int main( void ) {
    myVector<int> myVect;
    int number;
    myVector<string> myVect2;
    string myString;
    while( cin >> myString ) {
        myVect2.pushBack( myString );
    }
    if( ! cin.eof() ) {
        cout << "Invalid input.\n" << endl;
        return 1;
    }
    myVect.printVector();

    return 0;
}