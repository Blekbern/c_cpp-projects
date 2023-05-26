#include <iostream>
#include <string>
using namespace std;


// using templates with a class its methods defined outside its body


template <class T>
class myClass {
    private:
        T m_Value;
    public:
        myClass( T value );
        void printVal();
};

template <class T>
void myClass<T>::printVal() {
    cout << m_Value << endl;
}

template <class T>
myClass<T>::myClass( T value ) {
    m_Value = value;
}

int main( void ) {
    
    myClass<int> myVal( 10 );
    myVal.printVal();
    return 0;
}