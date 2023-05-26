#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
using namespace std;

/*                      ----- TO DO LIST ------
 * - COPY CONSTRUCTOR
 * - VECTOR WITH CONSTRUCTOR
 * - DESTRUCTOR 
 * 
 */


class CStudent {
    private:
    string m_Name;
    int m_Age;
    double m_Height;
    
    public:
    CStudent() {
        cout << "Constructor called." << endl;
    }

    void addAge( int age ) {
        m_Age = age;
    }
    void printAge() {
        cout << m_Age << endl;
    }
};


int main( void ) {

    vector <CStudent> Poggies;
    vector <CStudent>::iterator it;
    
    CStudent st1;                   // constructor called
    st1 . addAge( 16 );
    st1 . printAge();               // prints out 16

    Poggies.push_back( st1 );
    
    CStudent * st2 = new CStudent;  // constructor called
    CStudent * st3 = new CStudent;  // constructor called
    st2 -> addAge( 20 );
    st2 -> printAge();              // prints out 20
    st3 -> addAge( 21 );
    Poggies.push_back( *st2 );
    Poggies.push_back( *st3 );
    cout << "-----------------------" << endl;
    for( it = Poggies.begin(); it != Poggies.end(); ++it ) {
        it -> printAge();
    }
    
    return 0;
}