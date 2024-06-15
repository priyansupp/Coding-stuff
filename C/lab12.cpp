#include<bits\stdc++.h>
using namespace std;

struct Node{
    float data;
    Node* left;
    Node* right;
};


Node* getnewnode(float data){
    Node* temp= new Node;
    (*temp).data=data;
    (*temp).left=NULL;
    (*temp).right=NULL;
    return temp;
}

Node* Insert(Node* root, float n){
    if(root==NULL){
        root= getnewnode(n);
        return root;
    }
    if((*root).data>n){
        (*root).left=Insert((*root).left,n);
    }
    else{
        (*root).right=Insert((*root).right,n);
    }
    return root;
}


void Inorder(Node* root){
    if(root==NULL) return;
    Inorder((*root).left);
    cout<<(*root).data<<" ";
    Inorder((*root).right);
}

void Preorder(Node* root){
    if(root==NULL) return;
    cout<<(*root).data<<" ";
    Preorder((*root).left);
    Preorder((*root).right);
}

void leafnodes(Node* root){
    if(root==NULL) return;
    if((*root).left==NULL && (*root).right==NULL){
        cout<<(*root).data<<" ";
    }
    leafnodes((*root).left);
    leafnodes((*root).right);
}

int height(Node* root){
    if(root==NULL) return -1;
    int leftheight,rightheight;
    leftheight=height((*root).left);
    rightheight=height((*root).right);
    return max(leftheight,rightheight)+1;
}

float findsmallest(Node* root){
    if((*root).left==NULL) return (*root).data;
    findsmallest((*root).left);
}

float findbiggest(Node* root){
    if((*root).right==NULL) return (*root).data;
        findbiggest((*root).right);
}

int main()
{
    Node* head=NULL;

    ifstream File;
    File.open("tree.txt");
    string line;
    getline(File,line);
    File.close();
    stringstream ss;
    ss<<line;
    string temp;
    vector<float>input;
    while(!ss.eof()){
        ss>>temp;
        float t=stof(temp);
        input.push_back(t);
        temp="";
    }

    for(int i=0;i<input.size();i++){
        head=Insert(head,input[i]);
    }
    cout<<"Preorder traversal of the tree is: ";
    Preorder(head);
    cout<<endl;
    cout<<"Inorder traversal of the tree is: ";
    Inorder(head);
    cout<<endl;
    cout<<"Leafnodes of the tree are: ";
    leafnodes(head);
    cout<<endl;

    cout<<"Height of the tree is: "<<height(head)<<endl;
    cout<<"Smallest element in the tree is: "<<findsmallest(head)<<endl;
    cout<<"Largest element in the tree is: "<<findbiggest(head)<<endl;

}