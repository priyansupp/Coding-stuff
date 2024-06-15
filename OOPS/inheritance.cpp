#include <iostream>
using namespace std;

// NOTE : INHERITANCE INHERITS ALL THE MEMBER FUNCTIONS AND VARIABLES FROM PARENT TO CHILD CLASS(PRIVATE, PROTECTED, PUBLIC) => ALL ARE AVAILABLE
// BUT THE ACCESSIBILITY OF INHERITED MEMBER FUNCTION AND VARIABLES IS DECIDED BY VISIBILITY MODIFIERS.

// Inheritance allows hierarchy of classes that relate to eachother. Create a base class and inherit that base class in branch/derived classes. Helps avoiding code duplication.
// Put common code in base class

// Entity is any object in 3D world. It will have position, mass, and movement
class Entity {
public:
    float X, Y;

    void Move(float xa, float ya) {
        X += xa;
        Y += ya;
    }
};

// making a player class without inheritance
// class Player {
// public:
//     const char* Name;
//     float X, Y;

//     void Move(float xa, float ya) {
//         X += xa;
//         Y += ya;
//     }
// };


// Using inheritance: Because Player is also an Entity, and has all the member variables and methods of Entity(along with extra functions), we can inherit Player from Entity
// NOTE: Because Player inherited from Entity, Player is also an Entity(and obviously it is Player also). Thus Player has two types, Player and Entity. This is called POLYMORPHISM. Player has multiple forms.
class Player : public Entity {
public:
    const char* Name;           // additional Player member variable
    void PrintName() {          // additional Player member methods
        cout << Name << '\n';
    }
};

// POLYMORPHISM: Anywhere where we are using Entity(be in function parameter or as a variable), we can pass or use a Player, because Player is also an Entity.


int main() {
    Player player;
    player.Move(3, 5);      // method of Entity is accessible to Player
    player.X = -10;

    Entity entity;
    cout << sizeof entity << " " << sizeof player << '\n';      // sizeof player > sizeof entity because along with having all the variables and methods of Entity, player also has additional variables and methods. Inheritance here is as if the entire Entity class was copied and pasted in Player class.
    return 0;
}