#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
};
Node* pointerTOheadNode;
void Insert(int data, int n){
    Node* temp1;
    temp1= new Node();
    (*temp1).data=data;

    if(n==1){
        (*temp1).next=pointerTOheadNode;
        pointerTOheadNode=temp1;
    }
    else{
        Node* temp2=pointerTOheadNode;
        for(int i=0;i<n-2;i++){
            temp2=(*temp2).next;
        }
        (*temp1).next=(*temp2).next;
        (*temp2).next=temp1;
    }
}

void Print(){
    Node* temp=pointerTOheadNode;
        while(temp!=NULL){
        cout<<(*temp).data<<" ";
        temp=(*temp).next;
    }
    cout<<"\n";
}

void Reverserecursion(Node* p){
    if((*p).next==NULL){
        pointerTOheadNode=p;
        return;
    }
    Reverserecursion((*p).next);
    Node* q=(*p).next;
    (*q).next=p;
    (*p).next=NULL;
}


int main()
{
    pointerTOheadNode=NULL;
    Insert(2,1);
    Insert(3,1);
    Insert(8,3);
    Insert(5,2);
    Print();
    Reverserecursion(pointerTOheadNode);
    Print();
}