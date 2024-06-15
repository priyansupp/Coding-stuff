#include <iostream>
#include "Vector.h"
using namespace std;
// vector elements are heap allocated -> dynamic memory allocation

template<typename T>
void Print(const Vector<T> &v) {
    for(size_t i = 0; i < v.Size(); i++) {
        cout << v[i] << '\n';
    }
    cout << "--------------------------- Size is = " << v.Size() << "---------\n";
}

int main() {
    // Vector<string>v;
    // v.PushBack("Priyanshu");
    // v.PushBack("is");
    // v.PushBack("C++ ");
    // Print(v);
    // v.PopBack();
    // Print(v);
    // v.Clear();
    // Print(v);
    Vector<int>v2(5);
    v2[0] = 3;
    v2.PushBack(0);
    v2[2] = 4;
    Print(v2);
    Vector<int>v3(v2);
    Print(v3);
    return 0;
}