#include <iostream>
using namespace std;

// When applied to a global variable, the static keyword defines the global variable as having internal linkage, meaning the variable cannot be exported to other files.
static int x = 10;

// can be used and exported to other translation units(other cpp files in a program)
int w = 9;


class A{
public:
    // static in class means it has only one instance for the class and each object that we create is linked to it. (kind of object-less)
    const static int y = 5;     // const(or constexpr) static members can be initialized in the class itself.
    static int z;               // non-const static need be initialized outside the class through scope.
};
int A::z = 6;

int getID() {
    static int id = 0;
    return id++;
}

int main() {
    // cout << id;     // error because scope of id is local(local to the function) hence no other function can change the id.
    // Useful if we want to assign some id to each of our function call or object but we don't want other functions to change/modify it.
    cout << getID() << '\n';
    cout << getID() << '\n';
    cout << getID() << '\n';

    cout << A::y << ' ' << A().z << '\n';   // can be accessed with or without class's object.
    getchar();
    return 0;
}   