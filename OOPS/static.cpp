// https://youtu.be/f3FVU-iwNuA?list=PLlrATfBNZ98dudnM48yfGUldqGD0S4FFb
#include<bits/stdc++.h>
using namespace std;

// static variables in a class/struct means that variable is going to share memory with all instances of tha class. However many objects we create(instances), there will be only one instance of that variable(accessible to all).
// similarly is static method in class/struct
// Any class instance modifying a static variable, or using a static function changes that static variable for every instance. Hence both statics are independent of class instances. Static variables and instances can be called without class instances(they don't need it).

struct Entity {
    int x;
    static int y;
    void Print() {
        cout << x << ", " << y << '\n';
    }

    // static methods do not have a class instance(does not has the class instance parameter unlike non static methods who behind the curtains do have the class instance parameter as a function parameter), therefore they cannot have non static members
    static void Log() {
        // cout << x << ", " << y << '\n';     // because the Log method is static, it kind of is independent of all class instances(i.e not linked to any particular instance), hence it knows y but not x(as x is different for each instance)
        cout << "Log only y: " << y << '\n';
    }

    // passing the instance manually for using x
    static void Log(Entity entity) {
        cout << "Log both x and y: " << entity.x << ", " << y << '\n';
    }
};

int Entity::y;      // defining the static variables for the linker to link only once.

// the static method in class is just like having a function outside the class without any class instance as a parameter
// static void Log() {
//     cout << x << '\n';
// }


int main() {
    Entity e1;
    e1.x = 2;
    e1.y = 3;                   // y value in both the instances because y is shared
    
    // Entity e2 = {4, -1};     // cant use initializer with static
    Entity e2;
    e2.x = 5;
    Entity::y = -4;             // final y value. Because static variables are shared by all class instances, it doesn't makes sense to access them through class instances, we can directly access them without instances
    // but remember they are still a part of the class(they can be public, private, etc).
    // but it is more like a global variable for a class for all its instances, not for the whole translation unit.

    e1.Print();
    e2.Print();

    e1.Log();       // although the static method is being called through a class instance, it doesn't mean the method itself used or linked to that class instance, the static method is still independent. Logs only y
    Entity::Log();  // logs only y
    Entity::Log(e2);        // logs both x and y

    return 0;
}