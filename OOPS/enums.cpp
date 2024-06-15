// https://youtu.be/x55jfOd5PEE?list=PLlrATfBNZ98dudnM48yfGUldqGD0S4FFb
#include <iostream>
using namespace std;
// a = 1 b c = 4 d e f
// enums is a way to give a name to a value(int)
int a = 0;
int b = 1;
int c = 2;

// instead make an enum. enums by default are 32 bit integers, but we can change it to 1(char),2(short),4(int),8(long long) bit when declaring, but not float or double
enum Example : unsigned int {          // also a kind of datatype that contains other datatypes
    A, B, C = 4, D         // A = 0, B = 1, C = 4, D = 5(starts at 0 by default and increases by 1 by default)
};

int main() {
    // enum can only be set to another enum but can be compared to any int
    Example value = B;          // an enum can only be assigned to any value which is inside the enum
    // Example value2 = 1;         // even tho B=1, it will give an error, as we can only set enum value to one of its member values
    if(value == 1) {
        // do something
        cout << "Yes it is equal to B\n";
    }
    return 0;
}