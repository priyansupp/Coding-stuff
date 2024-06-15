#include<bits/stdc++.h>
using namespace std;

// c structs had just member variables, no member functions => that is why it was not an OOP language
// cpp structs can have member function and variables just like class => oop language
// structs and classes in cpp are almost similar, can same concepts like polymorphism, inheritance, encapsulation can be used in both

struct Person {
    // by default members are public, unlike class where members are private
private:
    int m_salary, m_age;
    char m_firstName[20];
    char *m_lastName;
public:
    Person() {}
    Person(int salary, int age, const char* first, const char* last) {
        m_salary = salary;
        m_age = age;
        strcpy(m_firstName, first);
        
        // m_lastName = last;          // whole of name is not copied into m_name, but only the MA m_name was pointing to has been changed to MA which name was pointing to
        m_lastName = new char[30];     // make it large enough, else program will crash
        strcpy(m_lastName, last);      // this works
        
        // %p for printing pointers in hex
        printf("%p, %p\n", m_firstName, first);          
        // printf("%d, %d\n", m_firstName, first);        // %d to print in int          
    }

    void print() {
        cout << m_firstName << ' ' << m_lastName << '\n' << m_age << ' ' << m_salary << '\n';
    }

    friend ostream& operator<<(ostream&, struct Person&);
} p1;                  // global declaration of a struct p1
struct Person p2;      // global declaration of a struct p2

ostream& operator<<(ostream& stream, struct Person& p) {
    stream << p.m_firstName << ' ' << p.m_lastName << '\n' << p.m_age << ' ' << p.m_salary << '\n';
    return stream;
}

int main() {
    struct Person p3 = {3000, 45, "Priyanshu", "Jaiswal"};  // local declaration of a struct p3
    // p3.print();
    cout << p3 << '\n';
    
    return 0;
}