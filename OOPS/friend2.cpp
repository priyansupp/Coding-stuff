// A friend function can be friends with multiple classes
// Most common use : when we need a function that uses private members of two or more classes. Member function cannot do this job, because it can only access private members of its own class.

#include <iostream>
using namespace std;

class B;        // forward declaration of class B so that compiler knows it while declaring friend function inside class A.
class A {
    int x;
public:
    A(int a) : x(a) {}
    friend int sum(A, B);
};
class B {
    int y;
public:
    B(int b) : y(b) {}
    friend int sum(A, B);
};

// uses private variables of both A, B to return the sum
int sum(A a, B b) {
    return a.x + b.y;
}

int main() {
    A a(3);
    B b(4);
    cout << "Sum = " << sum(a, b) << '\n';
    return 0;
}