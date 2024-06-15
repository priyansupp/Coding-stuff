#include<bits/stdc++.h>
using namespace std;

// string is array of characters

int main() {
    int* x = new int[5];        // allocates 5 blocks of 4Bytes each memory on heap. Total = 5*4 = 20Bytes
    delete[] x;                 // frees the memory of the complete array x(compiler somehow stores the size of the array)
    int y[10] = {5, 3, 7, 2, 1};
    cout << y << '\n';          // the name of the array is actually MA of the beginning of the array, i.e of 0th element
    int size = sizeof(y) / sizeof(int);     // this trick works only for stack allocated array, not in heap. For heap there's no way to know number of elements in the array(size must be maintained manually).
    
    // array of characters
    // ASCII(\0) = 0
    char name2[10] = {'N', 'i', 'n', 'a', 'h', 'e', 'h', 'e', 0, 'e'};        // in case of char array also, name2 holds MA of the 0th element of the array
    cout << name2 << '\n';          // but while printing, the compiler knows it is char array, so instead of printing MA, it prints the values(characters) in the array(by continuously increasing the pointer) unless it encounters \0(null termination character) or end of array.
    
    // const char array
    const char* name = "Priyanshu Kumar";         // cant use delete with this type of allocation. Use delete only if variable is allocated with "new"
    const char* last = "Jaisw\0al";               // name is a pointer. cout << name will keep printing to console by dereferencing the pointer and moving the pointer until it hits the \0 or end of array
    // last[2] = 't';
    cout << name << " " << last << '\n';

    // NOTE: cpp automatically appends \0 at the end of every const char array or string, so as it knows where the string ends.
    // We can also manually place it in between though.

    // strings
    string name3 = "Ra\0mesh4";       // if you hover the mouse on "Ra\0mesh4", you will see that string takes const char array, not char array. Therefore we cannot declare a char array and store it in a string.
    // string a = "hello" + " world";   // we can't do it because both are const char. 
    string a = "hello", b = " world";
    // with string class comes a lot of methods also that we can use
    cout << name3 << " " << name3.size() << '\n';
    
    a += b;         // actually makes appends a and b and reasigns in a. That's why this works
    bool contains = a.find("lo") != string::npos;   // npos is illegal position

    return 0;
}