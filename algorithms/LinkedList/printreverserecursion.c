//printing elements in reversed order rather than actually reversing the list.


#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* Insert(struct Node* pointerTOheadNode, int x, int n){
    struct Node* temp1;
    temp1= (struct Node*)malloc(sizeof(struct Node));
    (*temp1).data=x;

    if(n==1){
        (*temp1).next=pointerTOheadNode;
        pointerTOheadNode=temp1;
    }
    else{
        struct Node* temp2=pointerTOheadNode;
        for(int i=0;i<n-2;i++){
            temp2=(*temp2).next;
        }
        (*temp1).next=(*temp2).next;
        (*temp2).next=temp1;
    }
    return pointerTOheadNode;
}

void Print(struct Node* p){
    if(p==NULL) return;   //exit condition.
    printf("%d ",(*p).data);   //first print the value in the node
    Print((*p).next);     //recursisve call
}

void Printiterative(struct Node* pointerTOheadnode){
    struct Node* temp=pointerTOheadnode;
    while(temp!=NULL){
        printf("%d ",(*temp).data);
        temp=(*temp).next;
    }
    printf("\n");
}

// uses backtracking
void Printreverse(struct Node* p){
    if(p==NULL) return;   //exit condition.
    Printreverse((*p).next);     //recursisve call
    printf("%d ",(*p).data);     //prints last value in the node
}



int main()
{
    struct Node* pointerTOheadNode=NULL;   //local variable this time.
                       //in all the declared functions we need to pass pointerTOheadNode as its local argument because it's not globally accessible.

    pointerTOheadNode = Insert(pointerTOheadNode,2,1);
    pointerTOheadNode = Insert(pointerTOheadNode,3,1);
    pointerTOheadNode = Insert(pointerTOheadNode,8,3);
    pointerTOheadNode = Insert(pointerTOheadNode,5,2);
    Print(pointerTOheadNode);
    printf("\n");
    Printreverse(pointerTOheadNode);
    return 0;
}
