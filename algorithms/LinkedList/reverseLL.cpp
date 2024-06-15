#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node* next;
};

Node* Insert(Node* pointertoheadnode, int x, int n){
    Node* temp1;
    temp1= new Node();
    (*temp1).data=x;

    if(n==1){
        (*temp1).next=pointertoheadnode;
        pointertoheadnode=temp1;
    }
    else{
        Node* temp2=pointertoheadnode;
        for(int i=0;i<n-2;i++){
            temp2=(*temp2).next;
        }
        (*temp1).next=(*temp2).next;
        (*temp2).next=temp1;
    }
    return pointertoheadnode;
}

void Print(Node* pointertoheadnode){
    Node* temp=pointertoheadnode;
    while(temp!=NULL){
        cout<<(*temp).data<<" ";
        temp=(*temp).next;
    }
    cout<<"\n";
}

Node* Reverse(Node* pointertoheadnode){
    Node *current,*prev,*following;
    current=pointertoheadnode;
    prev=NULL;
    while(current!=NULL){
        following=(*current).next;
        (*current).next=prev;
        prev=current;
        current=following;
    }
    pointertoheadnode=prev;
    return pointertoheadnode;
}
int main()
{
    Node* pointertoheadnode=NULL;   //local variable this time.
                       //in all the declared functions we need to pass head as its local argument because it's not globally accessible.

    pointertoheadnode = Insert(pointertoheadnode,2,1);
    pointertoheadnode = Insert(pointertoheadnode,3,1);
    pointertoheadnode = Insert(pointertoheadnode,8,3);
    pointertoheadnode = Insert(pointertoheadnode,5,2);
    Print(pointertoheadnode);
    pointertoheadnode=Reverse(pointertoheadnode);
    Print(pointertoheadnode);
    return 0;
}
