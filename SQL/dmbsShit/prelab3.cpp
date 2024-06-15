#include<bits/stdc++.h>
using namespace std;
int d, t;

struct Node{
    bool isLeaf;
    vector<int>data;
    vector<Node*>ptrs;
};

Node* root;

void Insert(Node* ptrroot, int x){
    Node* temp = ptrroot;
    if(temp == NULL){
        ptrroot = new Node();
        (*ptrroot).data.push_back(x);
        return;
    }
    if(temp->isLeaf){
        if(temp->data.size() == 2 * d){
            Split(x);
        }else{
            temp->data.push_back(x);
        }
        return;
    }
    else{
        for(int i = 0; i < temp->ptrs.size(); i++){
            
        }
    }
}

int main()
{
    root = NULL;
    cin >> d >> t;
    while(1){
        int x;
        cin >> x;
        if(x == 1){
            int y;
            cin >> y;
            Insert(root, y);
        }else if(x == 2){
            Display();
        }else{
            break;
        }
    }
    return 0;
}


