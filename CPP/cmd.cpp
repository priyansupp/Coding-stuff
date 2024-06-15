#include <iostream>
using namespace std;

// int main(int argc, char*[] argv) {}  // argv is array of char pointers(c type strings)
int main(int argc, char** argv) {
    cout << "There are " << argc << " arguments.\n";
    for(int i = 0; i < argc; i++) {
        cout << argv[i] << '\n';
    }
    int x = 2;
    int &y = x;     // y has reference of x
    int *p1 = &x, *p2 = &y; // print address of both the variables, it'll be different.
    cout << p1 << ' ' << p2 << '\n';
    return 0;
}

// g++ cmd.cpp -o cmd       => to compile the cpp file
// ./cmd cmd1 cmd2 cmd3     => to run the program

// Run with following commands
// ./cmd hello world
// ./cmd "hello world"
// ./cmd \"Hello World\"    => prints backslash also

