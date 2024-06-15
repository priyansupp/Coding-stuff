// Resource Acquisition Is Initialization
#include <iostream>

template<typename T>
class Array {
private:
    size_t m_size;
    T *m_array;
public:
    Array(size_t size) : m_size(size) {
        m_array = new T[m_size];
    }
    ~Array() {
        delete[] m_array;
        std::cout << "Destructor has been called.\n";
    }

    const T& operator[] (size_t index) const {
        return m_array[index];
    }
    T& operator[] (size_t index) {
        return m_array[index];
    }

};

int main(int argc, char * argv[]) {
    const Array<int> myArr(10);
    std::cout << myArr[2] << '\n';
    for(size_t i = 0; i < 10; i++) {
        std::cout << i << ' ' << myArr[i] << '\n';
    }
}
// As soon as the program finishes and myArr(stack allocated) goes out of scope, its destructor is automatically called which destroys the array(heap allocated).
// No need to manually destroy the array and worry about memory management(memory leak).
// This is how the smart pointers also work.
// Thus, we use smart pointers(shared_ptr, unique_ptr) to avoid memory management ourselves like in Game dev(for memory safety at all stages).



