#include <iostream>
using namespace std;

class Integer {
private:
    int x;
public:
    Integer(int x) : x(x) {}
    Integer() {}

    // preincrement operator overloaded
    Integer operator++() {
        Integer temp;
        temp.x = ++x;       // the RHS x belongs to caller object's x
        return temp;
    }

    // postincrement operator overloaded
    // HERE, BOTH PRE AND POST INCREMENT CALL THE SAME OPERATOR OVERLOADED FUNCTION. THIS WILL CONFUSE THE COMPILER, WHICH OPERATOR SHOULD BE RESOLVED FOR WHICH OPERATOR. HENCE TO RESOLVE THIS ISSUE, C++ COMPILER ASKS FOR PASSING AN ADDITIONAL (int) PARAMETER IN THE "POSTINCREMENT" OPERATOR OVERLOADING(ONLY IN POST, NOT IN PRE) => THIS MAKES SURE THAT WHICH OPERATOR IS BEING OVERLOADED.
    Integer operator++(int) {
        Integer temp;
        temp.x = x++;
        return temp;
    }

    void show() {
        cout << "x = " << x << '\n';
    }

};

int main() {
    Integer a(3), b, c;

    // position of operator(before or after the caller object) is decided based on its general use with primitive dataypes. Like + is used after caller object, i.e x = a+b and not x = +ab

    // preincrement is used after varible, hence it is placed before
    b = ++a;    // reduces to b = a.operator++()

    // postincrement is used before variable, hence it is placed after
    c = a++;    // reduces to c = a.operator++(3) or any number you like to pass, does not matter

    c = a.operator++(9);

    // HERE, BOTH PRE AND POST INCREMENT CALL THE SAME OPERATOR OVERLOADED FUNCTION. THIS WILL CONFUSE THE COMPILER, WHICH OPERATOR SHOULD BE RESOLVED FOR WHICH OPERATOR. HENCE TO RESOLVE THIS ISSUE, C++ COMPILER ASKS FOR PASSING AN ADDITIONAL (int) PARAMETER IN THE "POSTINCREMENT" OPERATOR OVERLOADING(ONLY IN POST, NOT IN PRE) => THIS MAKES SURE THAT WHICH OPERATOR IS BEING OVERLOADED.

    a.show();
    b.show();
    c.show();
    return 0;
}