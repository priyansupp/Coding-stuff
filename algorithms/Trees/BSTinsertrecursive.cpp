#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left = NULL;
    Node* right = NULL;
};

Node* pointerToroot;

void Insert(Node* &r, int x){    // notice, we are passing the pointer by reference (i.e not pointer but the reference of the pointer which points to the node, more like a double pointer). The address of the place which stores the address of some Node(points to the node). If passed without reference it'd have crated another pointer variable named r which stores the same MA as that of pointerToroot(when it'd have been first passed)
    if(r == NULL){              // works the case when pointerToroot == NULL i.e when the tree is empty.
    // r means directly deferenecing the reference. When r == NULL, there's no node linked to the MA stored in the pointer.
    // Note that it'd not have been possible had we not taken the pointer by reference as then when r == NULL, we'd have lost the link to the tree and the new node would have been hanging in the wild, unconnected to the tree. 
    // r == nullptr means r is a pointer variable which stores MA of no-where(does not contain any MA), practically uninitialized variable(we compare the value stored in the pointer variable).
    //       500, 5
    //     /      \
    //   /         \
    // 300, 3       nullptr
    // --500 is the MA of the node, which is stored in Node* rr(say) and 5 is data stored in node. 300 is MA stored in left pointer variable and nullptr is MA stored in right pointer variable in node. Let us say the MA of the pointer rr itself is 1000, MA of the nullptr stored in right pointer variable(say rrr) in node is 1200. When Insert(rr, 6) is called it passes to Insert(nullptr, 6), where a new Node MA is assigned to the rrr pointer variable instead of nullptr, but as the changes are made to the same pointer variable(by dereferencing its MA and assigning MA of the Node), therefore the link between rrr and main tree is still preserved. TL;DR -> Essentially the right pointer variable does not chanages, only the value stored in it changes from nullptr to MA of new Node. Thus the right pointer variable is still linked to the tree before and after the insertion. Only by passing by reference we can make changes to the passed variable(by accessing it's MA), else it'd create a new local variable
        r = new Node(); // we can again simply dereference the r and store MA of newly created node in the pointer. What contained null before(with a Node in the tree) contains the MA of newly created node. Thus a new node has been added to the tree.
        r->data = x;
        return;
    }
    if(x < r->data){
        Insert(r->left, x);     // we are passing the reference of the r->left pointer, i.e the reference of the pointer(not the value of pointer itself) which stores the MA of the left node.
    }else{
        Insert(r->right, x);
    }
    return;
}

// Method 1 is analogous to this
// void add1(int &a) {
//     a += 1;
// }
// int a = 5;
// add1(a);                // a is now 6. a is changed by accessing its MA

// Method 2 is analogous to this
// int add1(int a) {
//     return a + 1;
// }
// int a = 10;
// a = add1(a);                // a is nown 11. a is changed by assigning it to the new value returned by the function

Node* pointerToroot2;
Node* Insert2(Node* r, int x)
{
    if (r == NULL) {
        r = new Node();
        r->data = x;
        return r;
    }

    if (x < r->data) {
        r->left = Insert2(r->left, x);  // the link between the newly created node and the tree is setup here. What's happening here differently from above is, the right pointer variable is assigned the value(MA of new Node) manually by getting returned by the function, therefore we don't need to intrinsically change the MA by passing by reference.
    }
    else {
        r->right = Insert2(r->right, x);
    }
 
    return r;
}

void Inorder(Node* r){
    if(r == NULL) return;
    Inorder(r->left);
    cout << r->data << " ";
    Inorder(r->right);
}
void Preorder(Node* r){
    if(r == NULL) return;
    cout << r->data << " ";
    Preorder(r->left);
    Preorder(r->right);
}
void Postorder(Node* r){
    if(r == NULL) return;
    Postorder(r->left);
    Postorder(r->right);
    cout << r->data << " ";
}

Node* TreeSearch(Node* temp, int key){
    if(temp->data == key || temp == nullptr) return temp;
    if(temp->data <= key){
        return TreeSearch(temp->right, key);
    }else if(temp->data > key){
        return TreeSearch(temp->left, key);
    }
    return nullptr;
}

Node* MAX(Node* temp){
    if(temp->right == nullptr) return temp;
    return MAX(temp->right);
}

Node* MIN(Node* temp){
    if(temp->left == nullptr) return temp;
    return MIN(temp->left);
}

Node* Successor(Node* x){       // succeessor of a node x is the node with the smallest key greater than x.key
    if(x->right != nullptr){
        return MIN(x->right);
    }
//     Node* y = x;         // this requires parent portion.
//     while(y != nullptr && x == y->right){
//         x = y;
//         y = y.parent
//     }
}

int main()
{
    pointerToroot = NULL;
    Insert(pointerToroot, 3);
    Insert(pointerToroot, 5);
    Insert(pointerToroot, 7);
    Insert(pointerToroot, 2);
    Insert(pointerToroot, 9);
    Insert(pointerToroot, 6);
    Insert(pointerToroot, 1);
    Insert(pointerToroot, 8);
    Insert(pointerToroot, 4);

    cout << "INORDER: ";
    Inorder(pointerToroot);      // gives ascending order of the tree
    cout << '\n' << "PREORDER: ";
    Preorder(pointerToroot);
    cout << '\n' << "POSTORDER: ";
    Postorder(pointerToroot);
    cout << '\n';
    Node* find = TreeSearch(pointerToroot, 5);
    if(find == nullptr) cout << "Could not find\n";
    else cout << "Found: " << find->data << '\n';

    cout << MAX(pointerToroot)->data << " " << MIN(pointerToroot)->data << '\n';


    // ANOTHER TREE
    pointerToroot2 = NULL;
    pointerToroot2 = Insert2(pointerToroot2, 3);
    pointerToroot2 = Insert2(pointerToroot2, 5);
    pointerToroot2 = Insert2(pointerToroot2, 7);
    pointerToroot2 = Insert2(pointerToroot2, 2);
    pointerToroot2 = Insert2(pointerToroot2, 9);
    pointerToroot2 = Insert2(pointerToroot2, 6);
    pointerToroot2 = Insert2(pointerToroot2, 1);
    pointerToroot2 = Insert2(pointerToroot2, 8);
    pointerToroot2 = Insert2(pointerToroot2, 4);

    cout << "INORDER: ";
    Inorder(pointerToroot2);      // gives ascending order of the tree
    cout << '\n' << "PREORDER: ";
    Preorder(pointerToroot2);
    cout << '\n' << "POSTORDER: ";
    Postorder(pointerToroot2);

    return 0;
}