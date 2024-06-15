// https://youtu.be/jELbKhGkEi0?list=PLlrATfBNZ98dudnM48yfGUldqGD0S4FFb
// https://youtu.be/JXHJZJXKP64?list=PLLYz8uHU480j37APNXBdPz7YzAi4XlQUF

// If some class is going to be Base class, do mark its destructor as virtual for sure, 100%.

#include <iostream>
using namespace std;

class A {
public:
    A() {
        cout << "Constructor of A\n";
    }
    ~A() {
        cout << "Destructor of A\n";
    }
};

class B : public A {
    int *x;
public:
    B() {
        x = new int;
        cout << "Constructor of B\n";
    }
    ~B() {
        delete x;
        cout << "Destructor of B\n";
        // ~A();            // done by the compiler
    }
};

class C {
public:
    C() {
        cout << "Constructor of C\n";
    }
    virtual ~C() {
        cout << "Destructor of C\n";
    }
};

class D : public C {
    int *x;
public:
    D() {
        x = new int;
        cout << "Constructor of D\n";
    }
    ~D() {
        delete x;
        cout << "Destructor of D\n";
        // ~C();           // done by the compilers
    }
};

void f() {
    B b;            // Destructor for this is called when f() is unwound from call stack(destroys the object).
    A *p = new B;   // Destructor is not called, because object of B pointed by p remains in memory even when f() is unwound from call stack because it has been allocated dynamic memory.
    delete p;       // Compiler does EARLY BINDING(COMPILE TIME POLYMORPHISM) to decide which destructor will be called when delete is used. 
    // Because the type of pointer is A, hence A's destructor is called which calls further destructors up the heirarchy.
    // B's destructor is never called (hence x in class B is never released) which leads to memory leak.

    // To solve the issue, compiler should do LATE BINDING(RUNTIME POLYMORPHISM) of destructor to decide which destructor to call first by looking at type of content of MA the pointer is pointing to.
    // Hence, make the destructor virtual.
    C *q = new D;
    delete q;
    // Destructor of D then Destructor of C
}

int main() {
    f();
    getchar();
}


