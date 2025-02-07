// Check RAII
#include <iostream>
#include <memory>       // unique_ptr, shared_ptr and weak_ptr are in memory


class Entity {
    int m_a, m_b;
public:
    Entity(int a, int b) : m_a(a), m_b(b) { std::cout << "Entity created.\n"; }
    ~Entity() { std::cout << "Entity destroyed.\n"; }
};

void foo(std::unique_ptr<Entity> e) {
    // do something
}

int main() {
    {
        Entity* e1 = new Entity(3, 5);
        std::unique_ptr<Entity> e2 = std::make_unique<Entity>(3, 4);        // How to make unique_ptr
        // std::unique_ptr<Entity> e3 = e2;        // unique_ptr cannot be reassigned
        // foo(e2);                                // unique_ptr cannot be copied
    }
    // Only the entity created via unique_ptr gets destroyed once it goes out of scope. e1 has memory leak(need to be destroyed manually).
    std::cin.get();
}

