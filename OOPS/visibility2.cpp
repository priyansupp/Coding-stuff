// stack is implemented via array <=> we cannot have public inheritance
#include <iostream>
using namespace std;

// In all inheritancew(private, protected or public); private members of base class are also inherited in derived class but they remain private to both the derived class as well as derived class's objects => cannot be accessed in the derived class or objects of derived class.

// public inheritance : public members are inherited public, protected members are inherited protected in derived class
// protected inheritance : public members are inherited protected, protected members are inherited protected in derived class
// private inheritance : public members are inherited private, protected members are inherited private in derived class

class Array {
    int a[10] = {0};
public:
    void set(int index, int value) {
        a[index] = value;
    }

    void print() {
        for(int i = 0; i < 10; i++) cout << a[i] << ' ' << (i == 9 ? '\n' : ' ');
    }
};

// only a is not accessible through Stack
class Stack : public Array {
    int top = 0;
public:
    void setTop(int value) {
        set(top, value);
        top++;
    }
};

// a is not accessible through Stack2 and set is not accessible through instances of Stack2
class Stack2 : private Array {
    int top = 0;
public:
    void setTop(int value) {
        set(top, value);
        top++;
    }

    void print() {
        // print();         // infinite loop
        // Note: print() is not static, but we are just using scope to figure out which print() to call => Array::print() is accessible to Stack2 class itself(as a private member), not just to its instances.
        Array::print();     // calls the correct print() of Array class => Scope resolution
    }
};


int main() {
    Array arr;
    arr.set(3, 4);
    arr.print();

    Stack s1;
    s1.setTop(9);
    s1.set(3,5);           // but this shouldn't be possible in a stack. We must protect all member functions and variables of Array to be accessible through Stack instances. Hence we do private/protected inheritance => public becomes private/protected respectively
    s1.print();

    Stack2 s2;
    s2.setTop(7);
    // s2.set(4, 5);       // error => inaccessible because set() has become private in Stack2
    s2.print();            // print() defined publicly in the Stack2 class has been called, which in turn calls the private member inherited from Array. Note: Array::print() is private and thus cannot be called via instances
    return 0;
}