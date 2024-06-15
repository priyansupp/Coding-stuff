// https://youtu.be/I-hZkUa9mIs?list=PLlrATfBNZ98dudnM48yfGUldqGD0S4FFb
#include<bits/stdc++.h>
using namespace std;

// template allows to define a template that gets compiled by our usage. Kind of compiler writing code for us.
// STL: Standard Template Library uses templates heavily

// void Print(int value) {
//     cout << value << '\n';
// }

// overloading the function with different datatype
// void Print(string value) {
//     cout << value << '\n';
// }

// void Print(float value) {
//     cout << value << '\n';
// }

// using templates(evaluated at compile time)
// the template function doesn't exist unless the function is called and the compiler forms the function with that typename
template<typename T>
void Print(T value) {
    cout << value << '\n';
}

template<typename T, size_t size>
class Array {
private:
    T m_Array[size];
public:
    int GetSize() const {return size;}
};

int main() {
    Print(5);               // implicit type casting. void Print(int value) function gets created using the template at compile time
    Print<string>("hello"); // explicit type casting
    Print<int>(4.6f);

    // vectors work just like that:
    Array<int, 5> array;         // This makes a new class like below and instantiate it with array
    // class Array {
    // private:
    //     int m_Array[5];
    // public:
    //     int GetSize() const {return size;}
    // };
    cout << array.GetSize() << '\n';

    Array<float, 10> array2;    // This makes a new class like below and instantiate it with array2
    // class Array {
    // private:
    //     float m_Array[10];
    // public:
    //     int GetSize() const {return size;}
    // };
    return 0;
}
