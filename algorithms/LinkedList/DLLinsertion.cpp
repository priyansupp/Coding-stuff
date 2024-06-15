#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node* next;
    Node* prev;
};

Node* pointerToheadNode;

Node* getnewNode(int x){
    Node* newNode=new Node();   // newNode has the address(points) to the newly created node.
    (*newNode).data=x;
    (*newNode).prev=NULL;
    (*newNode).next=NULL;
    return newNode;             //address of the newly created node is returned.
}

void Insert(int x, int n){
    Node* temp1= getnewNode(x);     // temp has address of newly created node, points to the newly created node.
    if(n==1){       //insert at head
        if(pointerToheadNode==NULL){   //DLL is initially empty
            pointerToheadNode=temp1;
        }
        else{
            (*pointerToheadNode).prev=temp1;  //prev of initial head node linked to newly created node now.
            (*temp1).next=pointerToheadNode;  //next of newly created node linked to initial head node(pointerToheadNode had MA of initial head node).
            pointerToheadNode=temp1;          //pointerToheadNode points to newly created node now.
        }
    }
    else{
        Node* temp2=pointerToheadNode;    //creating a new pointer and traversing all the way to n-1 th node.
        for(int i=0;i<n-2;i++){      //loop for n-2 times takes us to (n-1)th node.
            temp2=(*temp2).next;
        }
        (*temp1).next=(*temp2).next;   //newly created node to be pointed at nth node(nth node before insertion).
        if((*temp2).next!=NULL) (*(*temp2).next).prev=temp1;   //this won't execute if insertion at end.
        (*temp1).prev=temp2;                                   //linking newNode previous to initial last node.
        (*temp2).next=temp1;                                   //linking initial last node next to newNode.
    }
}

void Printforward(){
    Node* temp=pointerToheadNode;
    cout<<"FORWARD: ";
    while(temp!=NULL){
        cout<<(*temp).data<<" ";
        temp=(*temp).next;
    }                    
}
void Printback(){
    Node* temp=pointerToheadNode;
    cout<<"\t\tBACKWARD: ";
    if(temp==NULL) return;
    while((*temp).next!=NULL) temp=(*temp).next;
    while(temp!=NULL){
        cout<<(*temp).data<<" ";
        temp=(*temp).prev;
    }
    cout<<"\n";
}

int main()
{
    pointerToheadNode=NULL;
     Insert(2,1); Printforward(); Printback();  //{2}
     Insert(4,2); Printforward(); Printback();  //{2,4}
     Insert(5,1); Printforward(); Printback();  //{5,2,4}
     Insert(8,3); Printforward(); Printback();  //{5,2,8,4}
     return 0;
}
