#include <iostream>
using namespace std;

// How can we create copy of an object?
// 1. Copy constructor
// 2. Copy assignment operator

class A {
public:
    int x;
    int *p;
    A() {}
    A(int i, int j) {
        p = new int;
        *p = i;
        x = j;
    } 

    // shallow copy
    A(const A& a) {
        p = a.p;    // p stores the same MA as in the a.p, hence both are pointing to same memory block. Any change in that memory block content would be reflected in both.
        x = a.x;    
    }

    ~A() {
        delete p;
    }
};

class B {
public:
    int x;
    int *p;
    B() {}
    B(int i, int j) {
        p = new int;
        *p = i;
        x = j;
    }

    // deep copy
    B(const B& b) {
        p = new int;    // p takes a new memory block
        *p = *(b.p);    // and just copies the content of b.p into its own new memory block. Hence both have same content but different memory blocks.
        x = b.x;
    }

    ~B() {
        delete p;
    }
};

int main() {
    A a1(2, 4);
    A a2 = a1;         // copy constructor
    *(a1.p) = 5;
    cout << *(a1.p) << ' ' << *(a2.p) << '\n';
    a1.~A();
    cout << *(a2.p) << '\n';        // memory block has been freed, hence garbage value

    B b1(3, 4);
    B b2 = b1;
    *(b1.p) = 5;
    cout << *(b1.p) << ' ' << *(b2.p) << '\n';
    b1.~B();
    cout << *(b2.p) << '\n';        // freeing b1's memory block does not affect b2's memory block
}