// Check RAII
#include <iostream>
#include <memory>       // unique_ptr, shared_ptr and weak_ptr are in memory


class Entity {
    int m_a, m_b;
public:
    Entity(int a, int b) : m_a(a), m_b(b) { std::cout << "Entity created\n"; }
    ~Entity() { std::cout << "Entity destroyed\n"; }
};

void foo(std::shared_ptr<Entity> e) {
    // do something
}

int main() {
    {
        Entity* e1 = new Entity(3, 5);
        std::shared_ptr<Entity> e2 = std::make_shared<Entity>(3, 4);        // How to make shared_ptr
        std::shared_ptr<Entity> e3 = e2;        // shared_ptr can be reassigned
        foo(e2);                                // shared_ptr can be copied
    }
    // Only the entity created via unique_ptr gets destroyed once it goes out of scope. e1 has memory leak(need to be destroyed manually).
    std::cin.get();
}

