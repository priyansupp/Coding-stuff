#include<bits/stdc++.h>
using namespace std;

// global static
static float n = 3.4;
void func() {
    // local static, local scope
    static int x;       // static variable is created only once and is  not deallocated until the program ends. Hence even in 2nd function call, the x will remain from what was before
    static const int y = 3;   // can initialise it also. It is static const, value won't change
    int z = 5;          // created everytime function is called
    cout << x << ' ' << y << ' ' << n << ' ' << z << '\n';
    n++;
    x++;
    z++;
    // y--;             // No can do
}

int main() {
    func();
    func();
    // cout << x;       // although the variable is static but scope is local
    cout << setprecision(10) << n << '\n';
    return 0;
}