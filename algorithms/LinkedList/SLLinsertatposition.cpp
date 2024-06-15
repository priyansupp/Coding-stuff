#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
};

Node* pointerTOheadNode;     //global variable.

int SizeOfList() {
    int size = 0;
    Node* temp = pointerTOheadNode;
    while (temp != NULL)
    {
        temp = temp->next;
        size++;
    }
    return size;
}

void Insert(int x, int n){

    if(n < 1 || n > SizeOfList() + 1) {
        cout << "Could not insert.\n";
        return;
    }

    Node* temp1;
    temp1= new Node();        // making new node and assigning the pointer to the new node.
    (*temp1).data=x;

    if(n==1){
        (*temp1).next=pointerTOheadNode;     //pointerTOheadNode and thus now temp1 points to first node now.
        pointerTOheadNode=temp1;              //pointerTOheadNode points to newly inserted node(new first node) at first position now.
                          //this 'if' works even if LL is empty as then pointerTOheadNode points to NULL and therefore the first now inserted at the first position also points at NULL.
    }
    else{
        Node* temp2=pointerTOheadNode;    //creating a new pointer and traversing all the way to n-1 th node.
        for(int i=0;i<n-2;i++){      //loop for n-2 times takes us to (n-1)th node.
            temp2=(*temp2).next;
        }
        (*temp1).next=(*temp2).next;   //newly created node to be pointed at nth node(nth node before insertion).
        (*temp2).next=temp1;           //(n-1)th node points to newly created node now.
    }
}
void print(){
    Node* temp = pointerTOheadNode;
    while(temp != NULL){    // we can directly iterate on temp looking when it crosses the last node as we don't have to maipulate anything, just print, i.e it does no harm even if we lose our linked list(when temp == NULL)
        cout << (*temp).data << " ";
        temp = (*temp).next;
    }
    cout << '\n';
}
int main()
{
    pointerTOheadNode=NULL;        //empty list
    Insert(2,1);      //list: 2
    Insert(3,2);      //list: 2 3
    Insert(4,1);      //list: 4 2 3
    Insert(5,2);      //list: 4 5 2 3
    Insert(2,5);
    Insert(8,1);
    Insert(1889,6);
    print();

}
