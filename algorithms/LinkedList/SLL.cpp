#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next = NULL;
};

Node* pointerTOheadNode;

void Insert(int x){
    Node* temp = new Node();        // a new Node() is created in memory, we know nothing about it(no name nothing), except that its Memory address is stored in temp. temp is pointing to that newly created node.
    (*temp).data = x;               // data is stored in this newly created node/cell by derferencing the temp pointer, now all that remains is linking this node to the list. temp itself is not the node, it just points to that newly created node which now stores x.
    if(pointerTOheadNode == NULL){  // then newly created node will act like the head node(first node) of the SLL
        pointerTOheadNode = temp;   // pointerTOheadNode now points to the newly created node(which ultimately became the head node) by taking MA of the newly created node from temp into pointerTOheadNode(itself).
    }else{
        Node* temp2 = pointerTOheadNode;
        while(temp2->next != NULL){     // if we iterate for temp2 != NULL, we will lose trackof LL once it becomes NULL and we wont be able to add our node in the end. Hence we need to keep track of our LL until the end and stop at the end to add our new node.
            temp2 = temp2->next;
        }
        temp2->next = temp;
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

int findMax(){
    Node* temp = pointerTOheadNode;
    int maxi = INT_MIN;
    while(temp != NULL){    // we can directly iterate on temp looking when it crosses the last node as we don't have to maipulate anything, just iterate and find max, i.e it does no harm even if we lose our linked list(when temp == NULL)
        maxi = max(maxi, (*temp).data);
        temp = temp->next;
    }
    return maxi;
}

int main()
{
    int n = 9;
    int arr[] = {6,4,7,4,18,11,45,7,9};
    pointerTOheadNode = NULL;
    for(int i = 0; i < n; i++){
        Insert(arr[i]);
    }
    print();
    cout << findMax();
    return 0;

}