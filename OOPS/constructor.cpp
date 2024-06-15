#include <iostream>
using namespace std;

class Entity {
public:
    float x, y;         // when uninitialized, it takes random numbers

    // a method for initialization
    void init() {
        x = 0.0f;
        y = 0.0f;
    }

    void Print() {
        cout << x << ", " << y << '\n';
    }

    // a constructor has name of the class and no return type, can have optional parameters
    Entity() {          // gets called automatically whenever a class is instanciated
        x = 2.0f;
        y = 8.7f;
    }

    // function overloading is supported for constructors also
    Entity(float _x, float _y) {
        x = _x;
        y = _y;
    }

    // Note: If we don't provide a constructor in class, the class uses the default constructor(there is always a constructor and that gets overwritten by ours)
    // the default constructor is PUBLIC and does nothing(does not initializes any member variable), much like below constructor
    // Entity() {}
    // in java, primitive data types are by default initialized by the default constructor to 0, unlike cpp.

};

class Log {
private:
    // METHOD: I
    // Log() {}                // this makes the default constructor private and hence inaccessible when instantialization of a class. Therefore we cannot instantiate this particular class, we can only use the static members
public:
    // METHOD: II
    Log() = delete;         // this deletes the constructor entirely hence class cannot be instantiated
    
    static void Write() {
        cout << "HELLO\n";
    }
};

int main() {
    Entity entity;
    // cout << entity.x << '\n';
    entity.Print();
    // entity.init();
    
    Entity entity2, entity3(3.901, 9.466);
    entity2.Print();
    entity3.Print();
    // Log l;       // throws error
    Log::Write();   // seems fine


    Entity* e = new Entity();           // automatically calls the Entity() constructor also
    Entity* e1 = new Entity(9, 0);
    Entity* e2 = new Entity[30];        // only assigns a block of 30*sizeof(Entity) memory and returns the starting MA to e2. Does not calls the constructor for any of the Entity in the array
    cout << e1->x << " " << e2[4].x  << " " << e2[5].x << '\n';
    return 0;
}