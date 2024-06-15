// https://youtu.be/UWAdd13EfM8?list=PLlrATfBNZ98dudnM48yfGUldqGD0S4FFb
#include<bits/stdc++.h>
using namespace std;

// Pure virtual functions are same as abstract method or interface in java, C# respectively.
// Pure virtual functions are not implemented in Base class and left to be implemented in each of its subclasses.
// Interface(in C#) is just like having a class with unimplemented methods, like a template for method for all subclasses
// a class with pure virtual function cannot be instantiated(because it is just a template)


// because Printable is abstract class(because it has pure virtual function), it cannot be instantiated, hence PrintClassName() would never be called on instance of Printable class.
// but for any class, if we do need to use GetClassName(), we can inherit that class from Printable. But to use GetClassName(), we need instance of that subclass, and if we have to make an instance, we need to implement the pure virtual function GetClassName() in it(else it'd be abstract class and not be initialized).
// therefore, everytime we use GetClassName(Printable* obj), we'd be certain that GetClassName() pure virtual function has been implemented inside the subclass of Printable for which we use this function.
class Printable {
public:
    virtual const string GetClassName() = 0;           // a pure virtual function
};
void PrintClassName(Printable* obj) {
    cout << obj->GetClassName() << '\n';
}



class Entity : public Printable {
public:
    virtual string GetName() = 0;           // = 0 is making it a pure virtual functions
    const string GetClassName() override {
        return "Entity";
    }
};

class Player : public Entity {       // Entity has already inherited from Printable, hence we do not need to inherit from Printable
private:
    string m_Name;
public:
    const char* Name;
    Player(const string& name) : m_Name(name) {}

    string GetName() override {
        return m_Name;
    }

    const string GetClassName() override {      // if we don't override it here, player's GetNameClass using Printable* will actually use Entity's GetNameClass. That's how virtual functions behave
        return "Player";
    }
};




int main() {
    // Entity* entity = new Entity();       // throws error because Entity is abstract class type(because of the virtual function inside it)
    Player* player = new Player("Priyanshu");            // Player can only be instantiated if the pure virtual function Entity::GetName() is overwritten in Player, else Player will also become abstract class(a template)
    PrintClassName(player);
    Player player2("Jaiswal");
    PrintClassName(&player2);

    // Entity entity;               // Entity is also still an abstract class(an interface) because it has a pure virtual function.
    return 0;
}

// use pure virtual functions when you want a generic method in all subclasses to be implemented. pure virtual functions gurantee that it is implemented, else cannot be instantiated

