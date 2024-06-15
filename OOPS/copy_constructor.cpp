// https://youtu.be/BvR1Pgzzr38?list=PLlrATfBNZ98dudnM48yfGUldqGD0S4FFb
#include <iostream>
// #include <string.h>     // for c-style string methods: strcpy, strcom, strlen, etc.
using namespace std;

// copying means copying data

// NOTE : COMPILER MAKES TWO CONSTRUCTORS, NAMELY DEFAULT AND COPY CONSTRUCTORS ON ITS OWN.
// 1. IF WE MAKE ANY CONSTRUCTOR ON OUR OWN, THEN COMPILER WON'T MAKE DEFUALT CONSTRUCTOR.
// 2. IF WE MAKE COPY CONSTRUCTOR ON OUR OWN, THEN COMPILER WON'T MAKE COPY CONSTRUCTOR NOR DEFAULT CONSTRUCTOR.


// make a String class
class String{
private:
    char* m_Buffer;
    unsigned int m_Size;
public:
    String() {}                             // default constructor

    String(const char* string) {
        m_Size = strlen(string);            // strlen() only counts till before \0 in the string
        m_Buffer = new char[m_Size + 1];    // +1 for the \0
        // strcpy(m_Buffer, string);        // or make a for loop
        // memcpy copies each data byte-by-byte into the destination buffer until m_Size bytes.
        memcpy(m_Buffer, string, m_Size);   // only copy till m_Size from string, i.e do not copy the m_Size+1 character as it may or maynot be \0. We can manually set it to \0 down below.
        m_Buffer[m_Size] = 0;               // setting the null termination
    }

    // copy constructor => Compiler won't make a copy constructor now
    // NOTE : You can access private members of a class from within the same class, even those of another instance.
    String(const String &s) {              // must pass the argument with const
        m_Size = s.m_Size;                 // s.m_Size is private, but accessible in class member function(here, constructor) of another instance.
        // m_Buffer = s.m_Buffer;          // just assigns the MA that s.m_Buffer is pointing to in m_Buffer. Both s and the new object being made will have their m_Buffer pointing to same MA => Changing m_Buffer from one will affect other's m_Buffer
        // BETTER WAY: ASSIGN NEW MA FOR NEW CLASS'S m_Buffer
        m_Buffer = new char[m_Size];
        strcpy(m_Buffer, (const char*)s.m_Buffer);      // works without typecasting also
    }

    // NOTE : WE CANNOT MAKE COPY CONSTRUCTOR BY PASSING THE CLASS IN ARGUMENT BY VALUE -> BECAUSE PASSING BY VALUE ITSELF WILL CALL A COPY CONSTRUCTOR, AND WILL END UP IN INFINITE LOOP
    // TOTALLY WRONG:
    // String(String s) {
    //     m_Size = s.m_Size;
    //     m_Buffer = new char[m_Size];
    //     strcpy(m_Buffer, s.m_Buffer);
    // }

    ~String() {
        delete[] m_Buffer;
    }

    friend ostream& operator<<(ostream& stream, const String& string);      // friend functions can access private members.
};

ostream& operator<<(ostream& stream, const String& string) {
    stream << string.m_Buffer;
    return stream;
}

int main() {
    int a = 2;
    int b = a;      // b is copy of a
    b = 3;          // only b changes, not a

    // pointers
    int* c = new int;
    int* d = c;         // d is a copy of pointer c, i.e both are pointing to the same MA
    *d = 4;             // it also changs value stored in MA of pointer c
    d++;                // d would be pointing somewhere else now, but c would still point at orignial MA

    // String class
    String string = "Priyanshu";
    String second = string;     // or String second(string);    => calls the copy constructor

    cout << string << '\n';
    cout << second << '\n';

    cin.get();  // waits for an input
    return 0;
}