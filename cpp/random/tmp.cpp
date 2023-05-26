#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

class CNumber {
    public:
        int m_Num;
        int m_Cnt = 0;
    CNumber( int num ) {
        m_Num = num;
        m_Cnt++;
    }
    CNumber() {};
    void getInfo() {
        cout << "Num: " << m_Num << " " << m_Cnt << "x" << endl; 
    }
};


int main( void ) {
    string str1 = "hello";
    string str2 = "motherfucker";
    
    cout << str1.length() - str2.length() << endl;
    return 0;
}