// Overloading insertion and extraction operators
#include <iostream>
using namespace std;

// cout is object of ostream class and has multiple overloads for <<(insertion) operator(one for each datatype)
// cin is object of istream class and has multiple overloads for >>(extraction) operator(one for each datatype)


class Complex {
private:
    int x, y;
public:
    Complex() {}
    Complex(int x, int y) : x(x), y(y) {}
    void show() {
        cout << x << ", " << y << '\n';
    }

    ostream& operator<<(ostream& stream) {
        stream << x << ", " << y;
        return stream;
    }

    // we cannot make an object of ostream or istream, hence we take reference
    friend istream& operator>>(istream&, Complex&);
    friend ostream& operator<<(ostream&, Complex);
};

// the operator >> hasn't been overloaded for Complex class but for cin class. But because we needed to use private members of class Complex, we made it friend function of Complex
istream& operator>>(istream& stream, Complex& c) {
    stream >> c.x >> c.y;
    return stream;
}

ostream& operator<<(ostream& stream, Complex c) {
    stream << c.x << ", " << c.y;
    return stream;
}



int main() {
    int x;
    // cin >> x; means cin.operator>>(x)    => >> is member function of object cin of class istream
    cin.operator>>(x);
    cout << x << '\n';


    Complex c1(3, 4), c2;
    cin >> c2;              // same as cin.operator>>(c2);
    cout << c1 << '\n' << c2 << '\n';

    // cascading: 
    // ((cout << c1) << c2) << c3;      // each bracket needs to be an object of ostream class so as we can use overloaded operator << on that. Hence in the friend function we return reference of ostream.
    // same with ((cin >> c1) >> c2) >> c3;


    // TO ACHIEVE THE SAME USING MEMBER FUNCTION: We pass the cout object in the operator function of caller object.
    c1 << cout;         // c1.operator<<(cout);
    // but this looks horrible, and not intuitive, hence we use it with friend function of Complex class.

    return 0;
}