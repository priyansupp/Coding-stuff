#include <iostream>
using namespace std;

class A {};

class B : public A {
    const int x;
    int &y;
    int c = 4, d = 1;
public:
    // Member Initializers List:
    // 1. const and references can only be initialized through member initializers list and not in the body of the constructor
    // 2. Call to constructor of parent must be done in initializers list.
    // 3. Initialization takes place in the order it is declared in the class. Here although we have initialized y,x,d but actual initialization would be x,y,d with A() always being called at the very first.
    B(int a, int &b) : A(), y(b), x(a), d(-2) {
        // Both of these are assignment not initialization
        // x = a;
        // y = b;       // assigns the value of b in y, does not initializes the reference.
        c = 10;         // this can be done in constructor body also.
    }

    int showb() const { return y; }
};

int main() {
    int b = 10;
    B obj(3, b);
    b++;            // Increasing b changes the y value in the object obj because y is the reference of b and vice-versa.s
    cout << obj.showb();
    return 0;
}