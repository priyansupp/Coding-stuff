// https://youtu.be/cUCy2ENJjW8?list=PLLYz8uHU480j37APNXBdPz7YzAi4XlQUF
// 1. Base class pointer can point to the object of its child(descendant) class
// 2. Derived class pointer cannot point to ancestor class object.

#include <iostream>
using namespace std;

class A {
public:
    void f1() {}
    virtual void f2() {}    // virtual keyword tells the compiler to do late binding of this method to the caller object(i.e at runtime) by looking at the type of object.
};

class B : public A {
public:
    void f1() {}                 // method overriding
    void f2() override {}        // method overriding(may or maynot write "override")
};

int main() {
    A *p, a;
    B b;
    p = &b;     // parent class pointer can point to object of descendant class
    b.f1();     // f1() of B is called

    // f1() of A will be called because of EARLY BINDING(COMPILE TIME POLYMORPHISM).
    p->f1();    // or (*p).f1();


    A *p2;
    p2 = &b;
    p2->f2();   // f2() of B will be called because of LATE BINDING/DYNAMIC BINDING/RUNTIME BINDING(RUNTIME POLYMORPHISM).
    // The compiler defers the binding of function f2() to p2 until runtime. At runtime, by seeing the type of content(here, object B) of MA that pointer p2 points to, the function f2() of B is bound to the call of f2().
}


