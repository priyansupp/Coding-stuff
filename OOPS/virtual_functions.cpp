// https://youtu.be/oIV2KchSyGQ?list=PLlrATfBNZ98dudnM48yfGUldqGD0S4FFb
#include <iostream>
using namespace std;

// if we mark a function virtual in Base class, we have option to override it in its subclasses.

class Entity {
public:
    string GetName() {
        return "Entity";
    }
};

class Player : public Entity {
private:
    string m_Name;
public:
    // constructor
    Player(const string& name) : m_Name(name) {}

    string GetName() {
        return m_Name;
    }

};

// if we have a function to print the name of any Entity, basically anything in our 3D world(remember everything in our 3D world is an entity), we will use this function.
// because everything in our 3D world is Entity(because inherited from it), passing any subclass instance of Entity should print the name of that Subclass object only.
void PrintName(Entity* entity) {
    cout << entity->GetName() << '\n';          // but actually it does not. It prints "Entity" for the name.
}


// VIRTUAL FUNCTIONS
class Entity2 {
public:
    virtual string GetName() {
        return "Entity";
    }
};

class Player2 : public Entity2 {
private:
    string m_Name;
public:
    Player2(const string& name) : m_Name(name) {}

    // string GetName() {
    //     return m_Name;
    // }

    // may or may not write override, both work. Override helps knowing that this function is overwritten
    string GetName() override {
        return m_Name;
    }

};

// now because the GetName() function is virtual now, the compiler will generate a V table for all virtual functions and use the correct GetName() for different Entity subclasses.
void PrintName2(Entity2* entity) {
    cout << entity->GetName() << '\n';
}


int main() {
    Entity* entity = new Entity();
    cout << entity->GetName() << '\n';          // works just fine, prints Entity

    Player* player = new Player("Priyanshu");
    cout << player->GetName() << '\n';          // works just fine, prints Priyanshu
    PrintName(player);                          // prints "Entity" for the name instead of "Priyanshu". We should have been able to print "Priyanshu" thanks to polymorphism, but it is not printing such because the function PrintName() assumes the pointer passed is of Entity only and hence uses its GetName() function.

    // VIRTUAL FUNCTIONS
    Player2* player2 = new Player2("Priyanshu2");
    PrintName2(player2);                        // works fine, prints "Priyanshu2".

    return 0;
}


// 1. Constructor and destructor can neither be virtual nor static.
// 2. Destructors cannot be overloaded, but constructors can.
// 3. A function cannot be virtual and static at the same time.


