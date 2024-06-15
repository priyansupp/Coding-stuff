// https://youtu.be/D8cWquReFqw?list=PLlrATfBNZ98dudnM48yfGUldqGD0S4FFb
#include <iostream>
using namespace std;

class Entity {
public:
    float x, y;
    int* z;
    void Print() {
        cout << x << ", " << y << ", " << *z << '\n';
    }

    Entity() {
        cout << "Created entity\n";
        x = 2.0f;
        y = 8.7f;
        z = new int;
        *z = 78;
    }
    
    // DESTRUCTOR
    // Method that runs everytime an object is destroyed. 
    // NOTE: It does not destroys the object, but it gets called when object is destroyed and can be used to clean memory, uninitialize memory that had been assigned to its member variables(here, z).
    // Gets called if an object in stack gets removed from stack or when an object in heap is deleted(using delete/free keyword), memory freed.
    // Cannot be static and doesn't takes arguments, hence cannot be overloaded => There can only be one destructor in a class
    ~Entity() {
        cout << "Destroyed entity\n";
        delete z;               
        // Heap allocated must be freed manually. Stack allocated memory of x, y will automatically get freed when object is deallocated/destroyed.
    }


};


void Function() {
    Entity e;
    e.Print();
    e.~Entity();        // destroys manually => it doesnot destryos the object itself, it just does what is written inside destructor, i.e free z
    e.Print();          // will get garbage value for z, because it has been freed => stores a random MA that contains garbage value.
}


int main() {
    Entity e1;      // the destructor for this will be called when it is deallocated from stack, which will happen once we get out of main function
    Function();     // the e object formed inside this function will only get destroyed once the program comes out of scope of Function() and thus its destructor will be called yet again. Place a breakpoint and see
    return 0;
}