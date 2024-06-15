#include <iostream>
#include <string.h>
using namespace std;

class String {
private:
    char* m_Buffer;
    int len = 0;
public:
    String() {}     // default constructor

    // parameterised constructor
    String(const char* res) {
        int n = strlen(res);
        m_Buffer = new char[n + 1];     // extra 1 for null character '\0'
        strcpy(m_Buffer, res);
        len = n;
    }

    // copy constructor
    String(const String& s) {
        int n = strlen(s.m_Buffer);
        m_Buffer = new char[n + 1];
        strcpy(m_Buffer, s.m_Buffer);
        len = n;
    }

    // copy assignment
    void operator=(const String& s) {
        if(this != &s) {        // if both are different instances, i.e it is not something like s = s
            int n = strlen(s.m_Buffer);
            m_Buffer = new char[n + 1];
            strcpy(m_Buffer, s.m_Buffer);
            len = n;
        }
    }

    // concatenation1
    void operator+=(const String& s) {
        int len2 = s.len;
        int total = len2 + len;

        char* temp = new char[len + 1];
        strcpy(temp, m_Buffer);
        delete[] m_Buffer;

        m_Buffer = new char[total + 1];
        strcpy(m_Buffer, temp);
        strcpy(m_Buffer + len, s.m_Buffer);   // copies the rest from position len...total
        delete[] temp;
        len = total;
    }

    // concatenation2
    const char* operator+(const String& s) {
        int len2 = s.len;
        int total = len + len2;
        char* temp = new char[total + 1];
        strcpy(temp, m_Buffer);
        strcpy(temp + len, s.m_Buffer);
        return temp;
    }

    // array index operator[]
    char& operator[](int index) {       // return type is reference, because we can change the value also using the referenc, like s[4] = 'a'
        if(index >= len) {
            cout << "Index out of bound\n";
            exit(0);
        }
        return m_Buffer[index];
    }

    // length
    int length() {
        return len;
    }

    // clear/erase
    void clear() {
        delete[] m_Buffer;
        len = 0;
    }

    friend ostream& operator<<(ostream&, const String&);
    friend istream& operator>>(istream&, const String&);


    ~String() {
        delete[] m_Buffer;
    }
};

ostream& operator<<(ostream& out, const String& s) {
    out << s.m_Buffer;
    return out;
}
istream& operator>>(istream& in, const String& s) {
    in >> s.m_Buffer;
    return in;
}

int main() {
    String s1;              // default constructor
    String s2 = "Hello";    // parameterised constructor
    String s3 = String("World !");  // parameterised constructor
    String s4 = s2;         // copy constructor
    String s5;              
    s5 = s3;                // copy assignment
    cout << s4 << " " << s5 << '\n';

    // can also do something like in copy assignment
    s2 = s2;
    cout << s2 << '\n';

    // concatenation1
    s2 += s5;
    cout << s2 << '\n';

    // concatenation2 and array index operator[]
    String s6 = s2 + s5;
    cout << s6 << '\n' << s6[4] << '\n';
    s6[5] = '4';
    cout << s6 << '\n';
    s6.clear();
    cout << s6;

    return 0;
}