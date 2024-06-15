#include <iostream>

class Array {
private:
    size_t m_size;
    int *m_array;
public:
    Array(size_t size) : m_size(size) {
        m_array = new int[m_size];
    }
    ~Array() {
        delete[] m_array;
        std::cout << "Destructor has been called.\n";
    }

    // getter(always const). Both const and non-const myArray would call this getter only.
    const int& operator[] (size_t index) const {
        return m_array[index];
    }

    // setter(should be non-const). non-const myArray will only call this setter. const myArray cannot call a setter(will call a getter) and as the return type of getter is const ref, hence the value cannot be set.
    int& operator[] (size_t index) {    // If I write "int& operator[] (size_t index) const {", the compiler cannot overload the function only based on return type, i.e it'll clash with the getter overload. Hence no const there.
        return m_array[index];
    }

    // No need to overload the setter for const myArray. 1) Because it cannot be overloaded like this. 2) const myArray cannot call a setter.
    // int& operator[] (size_t index) const {
    //     return m_array[index];
    // }
};

int main(int argc, char * argv[]) {
    const Array myArr(10);
    std::cout << myArr[2] << '\n';
    // myArr[4] = 1;    // cannot do this as myArray is const and hence [] operator will always call the overloaded operator with const function(cannot change values inside the function one). Hence getter will always called. And the getter returns const ref, hence cannot be modified.
    for(size_t i = 0; i < 10; i++) {
        std::cout << i << ' ' << myArr[i] << '\n';
    }

    Array myArr2(20);
    std::cout << myArr2[2] << '\n';
    myArr2[11] = 103;
}

