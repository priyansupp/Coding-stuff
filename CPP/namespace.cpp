#include <iostream>
using namespace std;    // the std namespace itself is in the iostream library

// 1. namespace is like a container for variables, functions, classes, etc..
// 2. Can be unnamed -> unnamed namespaces
// 3. If we make multiple namespaces with same name across multiple files in a program, then all the namespaces are combined into one

namespace myspace {
    int x, y = 5;   // variables in namespace

    // functions in namespace
    void f1();      // can define it outside the namespace
    void f2() {}

    // class in namespace
    class A {
    public:
        void f3();  // can define it outside the namespace
        void f4();  // can define it outside the class but inside namespace
    };
    void A::f4() {}
    A a;            // object in namespace
}
using namespace myspace;        // to access identifiers of myspace without writing myspace resolution
void myspace::f1() {}
void myspace::A::f3() {}

namespace space2 {
    using namespace myspace;        // copy-pastes all the members of myspace in space2
    A a2;                           // As class A is defined in myspace and now its definition is also in space2, hence we can directly instantiate the object of that class.
}


int main() {
    std::cout << myspace::y;
    x = 10;
    return 0;
}

