#include<bits/stdc++.h>
using namespace std;

// only mention type and default value
inline int add(int &, int &, int = 0);  // DECLARATIONW

// inline functions are replaced in line whenever they are called. Only light-weight functions can be inline. It is a request not a commandd, and thus can be ignored by the compiler
inline void func();


int main() {

    int a = 3, b = 5, c = 7;
    // CALLING
    cout << add(a, b) << '\n';
    cout << add(a, b, c) << '\n';

    // NOTE : CALLING A FUNCTION INVOLVES COPYING THE STACK POINTER, JUMPING TO ANOTHER MEMORY SEGMENT, EXECUTING AND RETURNING BACK. LOT OF OVERHEAD. WE CAN REMOVE THIS OVERHEAD WHEN THE FUNCTION IS SMALL, THEN THE COMPILER INSTEAD OF JUMPING TO NEW MEMORY LOCATION, JUST REPLACES THE CODE IN FUNCTION ON THE CALLED LINE, THUS SAVING TIME
    func();         // the function is actually replaced by the code written inside func() by the compiler
    return 0;
}

void func() {           // no need to mention inline here
    cout << "Hello world\n";
}

// DEFINITION
int add(int &a, int &b, int c) {
    return (a + b + c);
}

