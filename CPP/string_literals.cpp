#include<stdlib.h>
#include<bits/stdc++.h>
using namespace std;

// "anything", anything written inside "" is a const char pointer/array

int main() {
    const char x[3] = "ab";     // x[0]='a', x[1]='b', x[2]=\0
    const char name[] = "Pri\0ya";     // Implicit \0 at the end of every string
    cout << name << " " << strlen(name) << " " << sizeof(name) << '\n';       // strlen only counts till before \0, but sizeof returns the memory size of name in Bytes.
    
    // manipulating char array works because compiler makes a copy with the manipulated data and moves back the copy in original
    char last[] = "ue";    
    last[1] = '4';
    cout << last << '\n';

    // strcat(str1, str2): Concatenate str2 to str1 (result is stored in str1, therefore str1 must not be const)
    strcat(last, name);
    cout << last << '\n';

    // strcmp(str1, str2): It returns 0 if the two strings are equal, otherwise a value that is not 0
    int compare = strcmp(last, name);
    if(compare == 0) cout << "Both the strings are same\n";
    else cout << "Both are different strings\n";

    // string literals through pointers cannot be manipulated(banned). string class strings are mutable(read only) but C type strings(i.e const char*) is immutable.
    // RHS is const char array/pointer, LHS is char*. That's why this throws an error. Always use const char* xyz to initialize with "".
    char* lastname = "hello";   // will throw warning but will compile
    lastname[3] = '7';       // definitely banned, program will crash
    cout << lastname << '\n';


}