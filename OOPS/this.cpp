// this is a keyword.
// this is a local(scope limited to class member itself) object pointer to the current instance of a class.
// this is inherently passed to every member function of a class
// this cannot be modified

#include <iostream>
using namespace std;

void PrintEntity(const Entity& e);

class Entity{
private:
    int x, y;
public:
    Entity(int x, int y) {
        x = x; y = y;           // this won't work. It'll just reassign the function parameters to itself
        
        Entity* e = this;       // this is an Entity* which actually points to the current class instance for which the member method is being called.
        e->x = x;               // this will work
        (*e).y = y;

        // this will also work
        this->x = x;    
        (*this).y = y;

        Entity& e1 = *this;
        PrintEntity(e1);
        PrintEntity(*this);

        // delete this;     // bad code, although works
    }

    int GetX() const {
        // const int* means we cannot change the value at the MA stored in pointer
        const Entity* e = this; // in this case, because the function GetX() is const, hence the this becomes const Entity*
        // e->x = 6;            // hence this is banned

        const Entity& e1 = *this;
        // PrintEntity(e1);
        // PrintEntity(*this);
        return e->x;
        return this->x;
    }
};

void PrintEntity(const Entity& e) {
    // Print
    cout << e.GetX() << '\n';
}

int main() {
    Entity e(3, 5);
    int x = e.GetX();
    return 0;
}