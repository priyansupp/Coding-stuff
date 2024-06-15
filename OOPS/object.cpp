#include <iostream>
using namespace std;

class Entity {
private:
    string m_Name;
public:
    Entity() : m_Name("Unknown") {}
    Entity(const string& name) : m_Name(name) {}

    const string& GetName() const {      // const promises that we won't change any member variable inside the method
        return m_Name;
    }
};

int main() {
    Entity e1, e2("Priyanshu"), e3 = Entity("Jaiswal"); // all allocate the object on stack
    cout << e1.GetName() << " " << e2.GetName() << " " << e3.GetName() << '\n';
    Entity *e4, *e5;
    {
        Entity stack = Entity("Stack-entity");
        Entity *heap = new Entity("Heap-entity");
        e4 = &stack;
        e5 = heap;
    }
    cout << e4->GetName() << " " << e5->GetName() << '\n';
    return 0;
}