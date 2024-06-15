// https://www.youtube.com/watch?v=g0EGFSzba6k&list=PLLYz8uHU480j37APNXBdPz7YzAi4XlQUF&index=39
#include <iostream>
using namespace std;

// NOTE : INHERITANCE INHERITS ALL THE MEMBER FUNCTIONS AND VARIABLES FROM PARENT TO CHILD CLASS(PRIVATE, PROTECTED, PUBLIC) => ALL ARE AVAILABLE
// BUT THE ACCESSIBILITY OF INHERITED MEMBER FUNCTION AND VARIABLES IS DECIDED BY VISIBILITY MODIFIERS.

struct En {
    int a;       // default visibility is public
};

class Entity {
    int a;       // default visibility is private
private:         // only Entity class(and its "friend") can access private variables/methods
    int x, y;
    void Print() {
        cout << x << ", " << y << '\n';
    }

protected:      // only the Base class and its subclasses can use and access protected members, not the class instance directly.
    int z = 10;

public:         // anyone can use and access the public members
    Entity() {
        x = 2;
        Print();            // fine, because we are accessing Print() from inside the Entity class only
    }

    // we can use getters and setters to access and set x, y from outside class
    void setX(int _x) { x = _x; }
    int getX() { return x; }
};

// Inheriting all the members of class Entity
// private of Entity is available to objects of Player but not accessible neither to objects of Player nor to its member functions
// protected of Entity is available to objects of Player but not accessible to them. However it can be accessed by member functions of Player
// public of Entity is available to objects of Player and accessible to them as well as member functions of Player
class Player : public Entity {
public:
    Player() {
        // x = -4;             // not accessible
        // Print();            // not accessible
        cout << z << '\n';     // accessible
    }
    void visible() {
        cout << "I am visible\n";
    }
};

int main() {
    Entity e;              // e.Entity() totally works fine. If constructor were private, we wouldn't have been able to instantiate Entity
    // e.x = 8;            // not accessible but available
    // e.Print();          // not accessible but available
    // e.z;                // not accessible but available
    e.setX(-104);          // accessible and available
    cout << e.getX() << '\n';

    Player p;              // p also has the member variables a,x,y but they are private and cannot be accessed.
    // p.x;                // not accessible but available
    // p.Print();          // not accessible but available
    // p.z;                // not accessible but available
    p.setX(5);             // accessible and available
    p.visible();           // accessible and available
    return 0;
}