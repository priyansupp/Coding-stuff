// Singleton is a class which can be instantiated only once.
// Technically for such cases we don't even need class, we can directly work with raw data. 
// But it's better to have all data members and methods to be grouped together.
// We can equivalently make a namespace with the same name(acts like a single object of the class).

#include <iostream>
using namespace std;

class Admin {
private:
    static int count;           // keeps count of how many objects have been made.
    static Admin m_Instance;    // the already made static instance of Admin. This instance while being made can easily call the private constructor.
    Admin() {}
public:
    // Admin() {}      // we must make it private(do not delete it, as we still need to instantiate it once) it else anyone can create any number of objects of this class.

    // METHOD I: By making new instances of each time and checking the limit. This way we can control exactly how many objects can be made.
    // I need to make it static so I can call this method without creating an object of Admin
    static Admin* getInstance() {
        if(count >= 1) {
            return nullptr;
        }
        Admin *p = new Admin();     // this can easily call the private constructor
        count++;
        return p;
    }

    // METHOD II: By returning an already made static Admin object.
    Admin(const Admin& s) = delete;     // copy constructor must be deleted
    static Admin& getInstanceRef() {    // must be static so as to call it without an object
        return m_Instance;              // just return the reference of static m_Instance
    }

    int x = 5;
    void f1() {}
};
// instantiating static members
int Admin::count = 0;
Admin Admin::m_Instance;


int main() {

    // METHOD I:
    Admin *p;   // making a pointer does not require constructor(it is just a pointer to the object of type Admin, not the object itself).
    p = Admin::getInstance();
    if(p == nullptr) {
        cout << "Cannot create object\n";
    } else {
        cout << "Object created\n";
    }

    Admin *q;   // cannot make another object using method I.
    q = Admin::getInstance();
    if(q == nullptr) {
        cout << "Cannot create object\n";
    } else {
        cout << "Object created\n";
    }


    // METHOD II:
    Admin &r = Admin::getInstanceRef();     // here r is just a reference to that single static instance of the class residing in the class itself.
    Admin &s = Admin::getInstanceRef();     // this is not a new object, but just a new reference to the same static object.
    r.x = 7;
    cout << s.x << '\n';

    // All three are same, calling same m_Instance object's f1()
    Admin::getInstanceRef().f1();
    r.f1();
    s.f1();

    // If we could do something like this, then we would have been able to make new objects each time by copying the members of that static m_Instance object each time into the new object(here, t).
    // As we need to restrict this, hence we delete the copy constructor.
    // Admin t = Admin::getInstanceRef();
    return 0;
}