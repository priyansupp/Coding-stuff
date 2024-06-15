// https://youtu.be/mS9755gF66w?list=PLlrATfBNZ98dudnM48yfGUldqGD0S4FFb
#include <iostream>
using namespace std;

// operators are just functions that manipulate/access things in the program
// Ex: + - & * ~ new delete \ ; >> << , {} . sizeof typeid ::
// Note: Last 4 cannot be overloaded

// Operator overloading(is a compile-time polymorphism): Giving a new meaning to, or change behaviour of a particular operator. Not supported in java

struct Vector2 {
    float x, y;

    Vector2(float x, float y) : x(x), y(y) {}

    Vector2 Add(const Vector2& other) const {
        return Vector2(x + other.x, y + other.y);
    }

    // operator is just a function
    // indirect definition of operator+ using Add() function
    Vector2 operator+(const Vector2& other) const {
        return Add(other);
    }


    Vector2 Multiply(const Vector2& other) const {
        return operator*(other);            // calling the function operator*() with parameter other
    }
    // direct definition of operator*
    Vector2 operator*(const Vector2& other) const {
        return Vector2(x * other.x, y * other.y);
    }


    bool operator==(const Vector2& other) const {
        return x == other.x && y == other.y;
    }
    bool operator!=(const Vector2& other) const {
        return !(*this == other);
        return !operator==(other);          // just using the operator==() function
    }
};

// overloading << operator to directly print the result to output stream
ostream& operator<<(ostream& stream, const Vector2& other) {
    stream << other.x << ", " << other.y;
    return stream;
}

// int operator/(const int& x, const int& y) {
//     return x / (1 << y);
// }

int main() {
    Vector2 position(4.0f, 4.0f);
    Vector2 speed(0.5f, 1.5f);
    Vector2 powerup(4.5f, 7.0f);

    Vector2 result1 = position.Add(speed); 
    Vector2 result2 = position.Add(speed.Multiply(powerup));

    // with operator overloading
    Vector2 r1 = speed * powerup;
    Vector2 r2 = speed.operator*(powerup);  // Binary operator overloading
    // both are r1, r2 are same

    Vector2 result3 = position + speed * powerup;   // operator precedence in play, from right to left

    cout << result3 << '\n';
    if(result2 == result3) cout << "They are equal\n";
    if(result2 != result3) cout << "They are not equal\n";



    // suppose I wanted to overload / operator, so that x/y = x divided by 2^y
    // int r = 10 / 2;
    return 0;
}