// A class containing atleast one pure virtual function is an abstract class.
// Abstract class cannot be instantiated.

#include <iostream>
using namespace std;

class A {
public:
    void f1();         // just declaration of f1() means that definition is somewhere else(but there is).

    // void f2() = 0;
    // f2() = 0 means that the definition of this f2() function is not in this class or even outside, hence object of A must not be instantiated(=0 makes sure we cannot).
    // If we override f2() in all the derived classes of A, then we can make objects of B and call f2() of class B thus preventing call to f2() of A. [B b; b->f2();]
    // But we can still call f2() of A through object of derived class[using compile time polymorphism, A *p = new B; p->f2();]. Hence we make sure to have late binding of f2() in every derived class object of B(b).
    // Therefore we mark it virtual for late binding to occur.

    virtual void f2() = 0;
    virtual void f3() = 0;      // pure virtual function
};
void A::f1() {}

class B : public A {
public:
    // must be defined in derived class
    void f2() {

    }

    // or must be made virtual again in derived class
    virtual void f3() = 0;
};

class C : public B {
public:
    void f3() {}
};

int main() {
    
}


