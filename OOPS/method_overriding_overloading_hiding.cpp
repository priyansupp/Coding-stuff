#include <iostream>
using namespace std;

// NOTE: While calling a method through some object of a class, if a name match is found in either itself or any of its ancestors, the compiler won't check further up the tree for that method.
// If a name match is found 
        // => not exact function signature => Error
        // => exact function signature     => works fine(can be through overriding or overloading)
// If no match found till end => error

class A {
public:
    void f1() {}
    void f2() {cout<<"Printing from A!!\n";}
    void f3() {}
};


class B: public A {
public:
    void f1() {}        // Method overriding => exact same function declaration as in A, hence we are overriding f1() of A in B
    void f2(int x) {
        cout<<"printing from B "<<x<<"\n";
        // f2();
    }   // Method hiding => only name is same. Things like return type, number of parameters can be different.
    // The f2() {} of can never be called through object of B => f2() {} of A is hidden.
    
    // Method overloading => Different versions of same name functions(body, args, return type(atleast one thing) can(should) be different) in the same class
    void f4() {}
    void f4(int x) {}
};


int main() {
    B b;

    // EARLY BINDING => Compile time polymorphism => Compiler decides which f1 to call for "b" at compile time only by looking at type of object "b" and moving to parent and grandparent etc. to find the function declaration.
    // It searches only in current class and all gradually up its ancestor classes and stop once the exact same function is found.
    // "b" is of type B, hence the function f1() of B will be called
    b.f1();             // overrode f1() of A => Method overriding


    // f2() is declared in B, but not with exact same params as we are calling here, hence the search will result in no such function found(it won't search for f2() in parent class because it has been found in B itself, but not just with correct params) and thus compilation error.
    // b.f2();          // hiding method f2() of A from being called through object of B => Method hiding 
    b.f2(4);            // calls f2(int) of B

    // Method overloading
    b.f4();             // calls f4() {} in B
    b.f4(3);            // calls f4(int) {} in B

}





