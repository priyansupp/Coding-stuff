#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left = NULL;
    Node* right = NULL;
};

Node* pointerToroot;

void Insert(int x){
    if(pointerToroot == NULL){
        pointerToroot = new Node();
        pointerToroot->data = x;
        return;
    }
    Node* temp = pointerToroot;
    while(true){
        if(x >= temp->data){
            if(temp->right != NULL) temp = temp->right;
            else{
                temp->right = new Node();       // temp->right == NULL but now it'll store MA of newly created node, hence a node got linked to the tree
                (temp->right)->data = x;        // writing in the newly created node.
                break;
            }
        }else{
            if(temp->left != NULL) temp = temp->left;
            else{
                temp->left = new Node();
                temp->left->data = x;
                break;
            }
        }
    }

}


vector<int> Preorder(Node* root){      // [data, left, right], so the stack must be filled right then left so when it pops, the left is popped first then right.
    vector<int> preorder;           // stores the final traversal answer.
    if(root == nullptr) return preorder;

    stack<Node*>S;
    S.push(root);
    while (!S.empty())
    {
        Node* r = S.top();
        S.pop();
        preorder.push_back(r->data);

        if(r->right != nullptr){
            S.push(r->right);
        }
        if(r->left != nullptr){
            S.push(r->left);
        }
    }
    return preorder;
    
}

// different from preorder method
vector<int> Inorder(Node* root){    // [left, data, right]
    vector<int> inorder;           // stores the final traversal answer.
    if(root == nullptr) return inorder;

    stack<Node*>S;
    Node* r = root;
    while (1)
    {
        if(r != nullptr) {
            S.push(r);
            r = r->left;
        } else {
            if(S.empty()) break;
            r = S.top();
            S.pop();
            inorder.push_back(r->data);
            r = r->right;
        }
    }
    return inorder;
}

// using 2 stacks
vector<int> Postorder(Node* root){    // [left, right, data]
    vector<int> postorder;           // stores the final traversal answer.
    if(root == nullptr) return postorder;

    stack<Node*>S1, S2;
    S1.push(root);
    while(!S1.empty()) {
        Node* r = S1.top();
        S1.pop();
        S2.push(r);
        if(r->left != nullptr) {
            S1.push(r->left);
        }
        if(r->right != nullptr) {
            S1.push(r->right);
        }
    }

    while(!S2.empty()) {
        postorder.push_back(S2.top()->data);
        S2.pop();
    }
    
    return postorder;
}

Node* TreeSearch(int key){  // seraching for the key
    Node* temp = pointerToroot;
    while(1){
        if(temp == nullptr) return temp;
        if(temp->data < key){
            temp = temp->right;
        }else if(temp->data > key){
            temp = temp->left;
        }else{
            return temp;
        }
    }
}

Node* MAX(Node* temp){
    while(temp->right != nullptr){
        temp = temp->right;
    }
    return temp;
}

Node* MIN(Node* temp){
    while(temp->left != nullptr){
        temp = temp->left;
    }
    return temp;
}

int main()
{
    pointerToroot = NULL;
    Insert(3);
    Insert(5);
    Insert(7);
    Insert(2);
    Insert(9);
    Insert(6);
    Insert(1);
    Insert(8);
    Insert(4);

    cout << "INORDER: ";
    vector<int>inorder = Inorder(pointerToroot);    // gives ascending order of the tree
    for(int i : inorder) cout << i << " ";

    cout << '\n' << "PREORDER: ";
    vector<int>preorder = Preorder(pointerToroot);
    for(int i : preorder) cout << i << " ";

    cout << '\n' << "POSTORDER: ";
    vector<int>postorder = Postorder(pointerToroot);
    for(int i : postorder) cout << i << " ";
    cout << '\n';

    Node* find = TreeSearch(5);
    if(find == nullptr) cout << "Could not find\n";
    else cout << "Found: " << find->data << '\n';

    cout << MAX(pointerToroot)->data << " " << MIN(pointerToroot)->data << '\n';

    // ANOTHER TREE
    // pointerToroot2 = NULL;
    // pointerToroot2 = Insert2(pointerToroot2, 3);
    // pointerToroot2 = Insert2(pointerToroot2, 5);
    // pointerToroot2 = Insert2(pointerToroot2, 7);
    // pointerToroot2 = Insert2(pointerToroot2, 2);
    // pointerToroot2 = Insert2(pointerToroot2, 9);
    // pointerToroot2 = Insert2(pointerToroot2, 6);
    // pointerToroot2 = Insert2(pointerToroot2, 1);
    // pointerToroot2 = Insert2(pointerToroot2, 8);
    // pointerToroot2 = Insert2(pointerToroot2, 4);

    // cout << "INORDER: ";
    // vector<int>inorder = Inorder(pointerToroot2);    // gives ascending order of the tree
    // for(int i : inorder) cout << i << " ";

    // cout << '\n' << "PREORDER: ";
    // vector<int>preorder = Preorder(pointerToroot2);
    // for(int i : preorder) cout << i << " ";

    // cout << '\n' << "POSTORDER: ";
    // vector<int>postorder = Postorder(pointerToroot2);
    // for(int i : postorder) cout << i << " ";
    // cout << '\n';

    return 0;
}
