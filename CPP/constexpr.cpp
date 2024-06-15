// Any variable that should not be modifiable after initialization and whose initializer is known at compile-time should be declared as constexpr.
// Any variable that should not be modifiable after initialization and whose initializer is not known at compile-time should be declared as const.

#include <iostream>
using namespace std;

// runtime expression
int getInt() {
    int a;
    cin >> a;
    return a;
}

// may or may not be compile time const
const int getInt2() {
    int x;
    cin >> x;           /// works fine
    return 5;
}

// everything inside constexpr function body must be compile time expressions
constexpr int getInt3() {
    int x = 4;
    // int z;       // cannot have uninitialized local variable, as it can be any garbage value at compile time, hence not a constant expression
    // cin >> x;    // cannot have a runtime expression inside a constexpr function body
    return x;       // As everything in this function is a compile time expression, hence the value of x can be evaluated at compile time itself and can be returned as constexpr
    return 7;
    // Both the return statements work fine
}

int main() {
    const int a = 3;        // compile time constant
    const int b = getInt(); // runtime constant
    const int z = a + b;    // runtime constant
    int p = 3;              // not a constant at all
    const int q = p;        // runtime constant, because p only is not constant(its value will only be known at runtime)

    
    // constexpr must always be compile time constant
    constexpr int c = 5, d = 6;             // compile time constant
    constexpr int e = 3 + 10, f = c + d;    // e is compile time, and because c is known at compile time and d is constexpr itself, hence f is also constexpr
    // constexpr int g = getInt();             // value of getInt() would only be known at runtime, hence error
    // constexpr int h = a + b;                // b is runtime constant, hence h cannot be constexpr

    // constexpr int i = getInt2();            // return type must be constexpr
    constexpr int j = getInt3();            // works fine
    const int k = getInt2(), l = getInt3(); // works fine
    return 0;
}