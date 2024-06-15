// https://www.youtube.com/watch?v=2BP8NhxjrO0&list=PLlrATfBNZ98dudnM48yfGUldqGD0S4FFb&index=20
#include <iostream>
using namespace std;

int x;          // just like this is a type, a primitive type

class Player {  // this is a type of datatype definition, that is an encapsulation of primitive and non primitive types of data
public:
    int x, y;
    int speed;

    // this Move method is just the same as one declared outside the Player class scope. But because this one is inside player class only, it already has the reference to the player object on which the method is being called on.
    void Move(int xa, int ya) {
        x += xa * speed;
        y += ya * speed;
    }

};              // semicolon because it is definition of a datatype

// outside class scope
void Move(Player& player, int xa, int ya) {
    player.x += xa * player.speed;
    player.y += ya * player.speed;
}


int main() {
    Player player;          // Class(datatype) and its object(instance)
    player.x = 5, player.y = 6, player.speed = 10;
    player.Move(3, -2);
    return 0;
}