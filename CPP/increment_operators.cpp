#include<bits/stdc++.h>
using namespace std;

int main() {
    int a=1, b=2;
    a = --b - ++a + ++b - --a;
    // a = (b is used after decrement) – (a is used after increment) + (b is used after increment) – (a is used after decrement)
    // a = 1(a=1, b=1) – 2(a=2, b=1) + 2(a=2, b=2) – 1(a=1, b=2)
    // a = 1 – 2 + 2 – 1 = 0
    cout << "a = " << a << ", b = " << b << '\n';

    bool c = false, d = 3;      // c,d are converted into c = 0, and d = 1, and now increment operators are applied.
    ++d;                        // it is already 1, incrementing it won't take it anywhere
    cout << ++c << ' ' << c << ' ' << d << '\n';  // prints 1, 0, 1  => the second one is 0 because it has already been assigned the value of c from before, i.e 0
    cout << c;                                    // prints 1 => has been incremented
    // --c; c--;
    // --d; d--;
    // Cannot use decrement operators on bool.

    // cannot be applied on constants, but only on modifiable values
    // int e = 11++;
    // const int f = 2;
    // f++;

    int g = 'a';
    g++;
    cout << g << ' ' << (char)g << '\n';      // increases the ascii value

    char h = 'r';
    cout << ++h << ' ';     // becomes 's'
    cout << --h << '\n';    // becomes 'r' again

    int i = 42;
    // int j = ++i++;         // or j = --(i++) is not allowed. Multiple ++ and(or) -- cannot come together


    return 0;
}