#include <iostream>
using namespace std;

class A{
    int a;
public:
    A(int k) : a(k) {
        cout << "Constructor of A.\n";
    }
    A() {}              // because we made a constructor of A, hence we must explictly make default constructor of A(if to be called through constructor of B).
    ~A() {
        cout << "Destructor of A.\n";
    }
};

class B : public A{
    int b;
public:

    // CONSTRUCTOR
    // compiler makes a default constructor of B along with calling default constructor of A in member initializer list like below
    B() : A() {}
    // A default constructor of A is absolutely necessary in case we forget to call any other constructor of A(then compiler will call default constructor of A and if not present, would throw an error).


    B(int x) {}      // if we make a constructor, compiler won't make one for B. But even if we forget to call constructor of A, compiler would make a call to default constructor of A for every constructor in B
    // Hence the above line becomes, B(int x) : A() {}

    // calling specific constructor of A, then compiler won't call default constructor of A in initializers list.
    B(int x, int y) : A(x), b(y) {
        cout << "Constructor of B.\n";
    }   
    // Order of call:      1. Constructor of B
    //                     2. Constructor of A
    // Order of execution: 1. Constructor of A
    //                     2. Constructor of B

    // Default constructor of A will be called for all constructors of B by the compiler(if we don't ourselves call some constructor of A)


    // DESTRUCTOR
    ~B() {                  // destructor of parent is not called through member initializers list but explictly in last line of derived destructor.
        // do something
        cout << "Destructor of B.\n";
        // ~A();           // compiler adds this line at the very last line of destructor.
        // As destructors take no parameters, hence there's no need of calling destructor explictly, as it is always called like ~A(), which compiler can handle itself.
    }
};


int main() {
    B b(2, 3);
    return 0;
}