// UNARY OPERATOR OVERLOADING
#include <iostream>
using namespace std;

// NOTE : In binary operator overloading, the object to the left of operator is the caller object which calls the member operator function on object to the right
// Ex : c3 = c1 + c2    is same as c3 = c1.operator+(c2)
// But in Unary operator, the caller object can be to the left or right of operator, depends on how we use the operator with primitive datatypes
// Ex : c2 = -c1 and c3 = c2++      // both are unary operators overloaded for Complex class

class Complex {
private:
    int x, y;
public:
    Complex() {}
    Complex(int x, int y) : x(x), y(y) {}
    void show() {
        cout << x << ", " << y << '\n';
    }

    Complex operator-() {
        Complex temp(-x, -y);
        return temp;
    }
};

int main() {
    Complex c1(3, 4), c2;

    // Unary operator overloading, just negates the integers in c1
    c2 = -c1;               // just like x = -y
    c1.show();
    c2.show();
    return 0;
}