#include <iostream>
#include <cstring>
using namespace std;

class A {
    private:
        int m_X;
    protected:
        int m_Y;
        A() {
            cout << "This is A - protected" << endl;
        }
    public:
        int m_Z;
};

class B : private A {
    // m_X is not accesible from B
    // m_Y is private
    // m_Z is private
};

class C : protected A {
    // m_X is not accessible from C
    // m_Y is protected
    // m_Z is protected
};

class D : public A {
    // m_X is not accessible from D
    // m_Y is protected
    // m_Z is public
    public:
        int number;
        D( int number ) {
            m_Y = number;
            cout << m_Y << endl;
        }
};


int main( void ) {
    D hello( 69 );
    return 0;
}