//NEWFILE
//Pratisha Thakur
//2010110873


#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* Insert(struct Node* head, int data, int n){
    struct Node* temp1;
    temp1= (struct Node*)malloc(sizeof(struct Node));
    (*temp1).data=data;

    if(n==1){
        (*temp1).next=head;
        head=temp1;
    }
    else{
        struct Node* temp2=head;
        for(int i=0;i<n-2;i++){
            temp2=(*temp2).next;
        }
        (*temp1).next=(*temp2).next;
        (*temp2).next=temp1;
    }
    return head;
}

void Print(struct Node* p){
    if(p==NULL) return;   //exit condition.
    printf("%d ",(*p).data);   //first print the value in the node
    Print((*p).next);     //recursisve call
}

void MoveNode(struct Node** final, struct Node** start)
{
    struct Node* newNode = *start;
    assert(newNode != NULL);
 
    /* Advance the source pointer */
    *start = newNode->next;
 
    /* Link the old dest off the new node */
    newNode->next = *final;
 
    /* Move dest to point to the new node */
    *final = newNode;
}

struct Node* Sort(struct Node* head, struct Node* head2)
{
    struct Node T;
    struct Node* TT = &T;
    T.next = NULL;
    while (1)
    {
        if (head == NULL)
        {
            TT->next = head2;
            break;
        }
        else if (head2 == NULL)
        {
            TT->next = head;
            break;
        }
        if (head->data <= head2->data)
            MoveNode(&(TT->next), &head);
        else
            MoveNode(&(TT->next), &head2);
 
        TT = TT->next;
    }
    return(T.next);
}

int main()
{
    struct Node* head=NULL; 

    FILE* fpointer=fopen("AA.txt","r");
    char x[100];
    int i=1;
    while(fscanf(fpointer,"%s",x)==1){
        // printf("%d ",atoi(x));
        head=Insert(head,atoi(x),i);
        i++;
    }

    Print(head);
    printf("\n");

    struct Node* head2=NULL; 

    FILE* fpointer2=fopen("BB.txt","r");
    char y[100];
    i=1;
    while(fscanf(fpointer2,"%s",y)==1){
        head2=Insert(head2,atoi(y),i);
        i++;
    }

    Print(head2);
    struct Node* res=Sort(head,head2);

    printf("Final sorted linked list is: ");
    Print(res);


    return 0;

}