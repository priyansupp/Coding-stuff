// friend function
#include <iostream>
using namespace std;

class Complex {
private:
    int x, y;
public:
    Complex() {}
    Complex(int x, int y) : x(x), y(y) {}

    // member function => can access member variables and other member functions directly
    void show() {
        cout << x << ", " << y << '\n';
    }

    // Must be declared inside the function and defined outside
    // As it is not a member function, hence it can be declared inside private, public or protected.
    friend void fun(Complex);       // not a member function but a friend function of this class
};

// membership label is not required, i.e 
// void Complex::fun(Complex c) => WRONG
void fun(Complex c) {
    // cout << "Sum is = " << x + y << '\n';   // cannot directly access the member variables
    // Because it is friend of class Complex, hence it can access even the private members of the class
    cout << "Sum is = " << c.x + c.y << '\n';   // can access through the complex object passed
}

// void fun2(Complex c) {
//     // Because it is not a friend of class Complex, hence it cannot access the private members of the class
//     cout << "Sum is = " << c.x + c.y << '\n';
// }

int main() {
    Complex c1(3, 4), c2;
    // Complex::fun(c1);   // membership label is not required, because fun() is not a member function
    fun(c1);
    c1.show();
    c2.show();
    return 0;
}