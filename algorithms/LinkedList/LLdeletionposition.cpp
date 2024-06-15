//1. fix the links
//2. free the space


#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
};

Node* pointerTOheadNode;
void Insert(int x, int n){      // inserting at any position
    Node* temp1;
    temp1= new Node();
    (*temp1).data=x;

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

void Delete(int n){
    Node* temp1=pointerTOheadNode;
    if(n==1){
        pointerTOheadNode=(*temp1).next;
        delete temp1;   //free(temp1);
    }
    else{
        for(int i=0;i<n-2;i++){
            temp1=(*temp1).next;
        }      //temp1 points to (n-1)th Node now.
        Node* temp2=(*temp1).next;   //temp2 points to nth Node.
        (*temp1).next=(*temp2).next;  //temp1 points to (n+1)th Node.
        delete temp2;   //free(temp2);
    }
}

int main()
{
    pointerTOheadNode=NULL;
    Insert(2,1);      //list: 2
    Insert(3,2);      //list: 2 3
    Insert(4,1);      //list: 4 2 3
    Insert(5,2);      //list: 4 5 2 3
    Insert(2,5);
    Insert(8,1);
    Insert(48237484,6);
    Print();
    int n;
    cin>>n;
    Delete(n);
    Print();

}
