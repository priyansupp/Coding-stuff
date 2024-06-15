#include<stdio.h>


struct Node{
    float data;
    Node* left;
    Node* right;
};


struct Node* getnewnode(float data){
    struct Node* temp= (struct Node*)malloc(sizeof(Node));
    (*temp).data=data;
    (*temp).left=NULL;
    (*temp).right=NULL;
    return temp;
}

struct Node* Insert(struct Node* root, float n){
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

void Preorder(struct Node* root){
    if(root==NULL) return;
    cout<<(*root).data<<" ";
    Preorder((*root).left);
    Preorder((*root).right);
}

int height(struct Node* root){
    if(root==NULL) return -1;
    int leftheight,rightheight;
    leftheight=height((*root).left);
    rightheight=height((*root).right);
    return max(leftheight,rightheight)+1;
}

bool IdenticalTrees(struct Node *root1, struct Node *root2) {   
    if(root1 == NULL && root2 == NULL)  
          return true;  
      
      
    if(root1 == NULL && root2 == NULL)  
          return true;  
      
       
    if(root1 != NULL  && root2 != NULL) {  
            
          return ((root1->data == root2->data) &&  
                  (IdenticalTrees(root1->left, root2->left)) &&  
                  (IdenticalTrees(root1->right, root2->right)));  
    }  
    return false;  
}  

int main()
{
    struct Node* head=NULL;

    ifstream File;
    File.open("SHIVA1.txt");
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

    cout<<"Preorder traversal of SHIVA1 tree is: ";
    Preorder(head);
    cout<<endl;

    cout<<"Balanced factor of root of SHIVA1 tree is: "<<height((*head).left)-height((*head).right);
    cout<<endl;

    Node* head2=NULL;

    ifstream File2;
    File2.open("SHIVA2.txt");
    string line2;
    getline(File2,line2);
    File2.close();
    stringstream ss2;
    ss2<<line2;
    string temp2;
    vector<float>input2;
    while(!ss2.eof()){
        ss2>>temp2;
        float t=stof(temp2);
        input2.push_back(t);
        temp2="";
    }

    for(int i=0;i<input2.size();i++){
        head2=Insert(head2,input2[i]);
    }

    cout<<"Preorder traversal of SHIVA2 tree is: ";
    Preorder(head2);
    cout<<endl;

    if(IdenticalTrees(head,head2)) cout<<"Trees are identical";
    else cout<<"Trees are not identical";

}