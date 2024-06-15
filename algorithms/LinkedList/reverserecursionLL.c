#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* pointerTOheadNode;

void Insert(int x, int n){
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
}

void Print(){
    struct Node* temp=pointerTOheadNode;
    while(temp!=NULL){
        printf("%d ",(*temp).data);
        temp=(*temp).next;
    }
    printf("\n");
}

void Reverserecursion(struct Node* p){
    if((*p).next==NULL){
        pointerTOheadNode=p;
        return;
    }
    Reverserecursion((*p).next);
    struct Node* q=(*p).next;
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
    return 0;
}

