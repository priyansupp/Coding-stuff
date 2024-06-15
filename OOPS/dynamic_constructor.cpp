#include <iostream>
using namespace std;

class A {
    int *p;
    int x;
public:
    // This constructor gives a block of memory to one of its pointer member variables(dynamically allocated), hence it is dynamic constructor.
    // A dynamic constructor does not gives memory to object(infact like other constructor, it is called after object has been loaded in memory), instead it allocates dynamic memory to its member variables.
    A(int a, int b) {
        x = a;
        p = new int;
        *p = b;
        cout << "This is dynamic constructor.\n";
    }
};


int main() {
    A a(2, 3);
    return 0;
}