#include <iostream>
#include <cstring>
using namespace std;



class User {
    public:
        int m_UserID;
        string m_Name;
        User() { cout << "No parameter constructor called (user)" << endl; }
        User( int id, string name ) {
            m_UserID = id;
            m_Name = name;
            cout << "Parameter constructor called." << endl;
        }

        void printName( string name ) const {
            cout << "Username is: " << name << endl;
        }
        virtual void say() const {
            cout << "User is quiet." << endl;
        }
};

class Student : public User {
    public:
        Student() { cout << "No parameter constructor called (student)" << endl; }
        Student( int id, string name ) {
            m_UserID = id;
            m_Name = name;
            cout << "Parameter constructor called" << endl;
        }
        virtual void printName( string name ) const {
            cout << "Name of student is: " << name << endl;
        }
        void say() const {
            cout << "Student asks a question." << endl;
        }
};

class Teacher : public User {
    public:
        void printName( string name ) const {
            cout << "Teacher's name: " << name << endl;
        }

        virtual void say() const {
            cout << "Teacher teaches." << endl;
        }
};

int main( void ) {
    Student st;                     // calls User no par constructor then Student no par constructor
    st.User::say();                 // User is quiet
    st.say();                       // Student asks a question

    cout << "-----------------------------------------------" << endl;

    User * p = new Student;         // User no parameter constructor
    p -> say();                     // Student asks a question (User::say is virtual)
    p -> printName( "Luke" );       // Username is: Luke
    
    cout << "-----------------------------------------------" << endl;

    Student st2( 123, "Robert" );   // calls User no parameter constructor then Student parameter constructor
    
    cout << "-----------------------------------------------" << endl;

    User * t = new Teacher;
    t -> say();                     // Teacher teaches (BOTH VIRTUAL)
    t -> User::say();               // User is quiet
    t -> printName( "Adam" );       // Username is: Adam
    
    return 0;
}