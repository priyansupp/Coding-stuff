// https://youtu.be/mWgmBBz0y8c?list=PLlrATfBNZ98dudnM48yfGUldqGD0S4FFb
#include<bits/stdc++.h>
using namespace std;

// to define anonymous functions. We mostly use it as pass function pointers in another function
// ForEach function(much like JS forEach method) uses the function pointer to do something to each value in the vector values.
void ForEach(const vector<int>& values, void(*func)(int)) {
    for(const int& value : values) {
        func(value);
    }
    cout << '\n';
}


int main() {
    vector<int>values = {3, 1, -3, 5,1,0};
    ForEach(values, [](int value) {cout << value << ' ';});        // the second argument is the lambda function
    
    int a = 10;
    auto lambda = [a](int value) {cout << value + a << ' ';};      // the capture [a] passes outside variables in the lambda function
    auto lambda2 = [&a](int value) {a = -10; cout << value + a << ' ';};
    auto lambda3 = [a](int value) mutable {a = 0; cout << value + a << ' ';};      // use mutable to modify the capture value if passing by value in the lambda
    
    for(int i : values) {
        lambda(i);
    }
    cout << '\n';

    for(int i : values) {
        lambda2(i);
    }
    cout << '\n';
    cout << a << '\n';

    for(int i : values) {
        lambda3(i);
    }
    cout << '\n';

    // similarly we can define easy and small functions anywhere and assign to some variable to be called later with that variable
    return 0;
}

