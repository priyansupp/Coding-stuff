#include <iostream>
using namespace std;
class R {
    int *ptr;
    public:
    R() {
        cout << "Constructor\n";
        ptr = new int;
    }
    R(const R &r) {
        this->ptr = new int;
        cout << "Copy\n";
    }
    ~R() {
        cout << "DESc\n";
        delete ptr;
    }
};

int main() {
    R r = R();           // parameterised constructor
    R &r2 = r;           // no constructor is called, just a reference
    R a[4];              // calls constructor for all 4 of them
    a[3] = r2;            // calls no constructor
    // R* b = new R[4];     // calls constructor for all 4 of them

    // vector<R>v;
    // v.push_back(r);     // it takes r by reference. But in the push_back function, a new block is created to store r at the end of vector and whole content of r is copied into that block using copy constructor. Total = 1(to copy the current one)
    // v.push_back(r);     // at this point, vector size is 1, but we are pushing one more element, so size would double and previous all elements would be copied back into new block along with the current one. Total = 1(to copy previous one) + 1(for the current one)
    return 0;
}