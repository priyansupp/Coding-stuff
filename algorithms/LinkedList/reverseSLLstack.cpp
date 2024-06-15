#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
};

Node* head;
void Insert(int data, int n){
    Node* temp1;
    temp1= new Node();
    (*temp1).data=data;

    if(n==1){
        (*temp1).next=head;
        head=temp1;
    }
    else{
        Node* temp2=head;
        for(int i=0;i<n-2;i++){
            temp2=(*temp2).next;
        }
        (*temp1).next=(*temp2).next;
        (*temp2).next=temp1;
    }
}

void Print(){
    Node* temp=head;
    while((*temp).next!=NULL){
        cout<<(*temp).data<<" ";
        temp=(*temp).next;
    }
    cout<<(*temp).data<<"\n";
}

void Reversestack(){
    if(head==NULL) return;
    Node* temp1=head;
    stack<Node*>S;
    while(temp1!=NULL){
        S.push(temp1);   //storing only address of consecutive nodes in stack
        temp1=(*temp1).next;
    }
    Node* temp2=S.top();
    head=temp2;    //head now points to last element i.e S.top()
    S.pop();       //stack's top element is now second last element's address that needs to be stored in last element's next pointer i.e (*temp2).next
    while(!S.empty()){
        (*temp2).next=S.top();   
        S.pop();
        temp2=(*temp2).next;
    }
    (*temp2).next=NULL;   //final element reversed and linked to NULL
}


int main()
{
    head=NULL;
    Insert(2,1);      //list: 2
    Insert(3,2);      //list: 2 3
    Insert(4,1);      //list: 4 2 3
    Insert(5,2);      //list: 4 5 2 3
    Insert(2,5);
    Insert(8,1);
    Insert(48237484,6);
    Print();
    Reversestack();
    Print();
    return 0;
}