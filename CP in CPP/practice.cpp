#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define forr(i,n) for(ll i=0;i<n;i++)
#define pb push_back
#define ft              first
#define sd              second
#define rev(v)          reverse(v.begin(),v.end())
#define sort(v)         sort(v.begin(),v.end())
#define revsort(v)       sort(v.begin(),v.end(),greater<ll>())
#define minV(v)         *min_element(v.begin(),v.end())
#define maxV(v)         *max_element(v.begin(),v.end())




struct Node{
    char data;
    Node* next;
};
Node* head;

Node* getnewNode(char c){
    Node* newNode= new Node();
    (*newNode).data=c;
    (*newNode).next=NULL;
    return newNode;
}

void printoutput(string s){
    int l=s.length();
    
    char maxChar='a';
    char minChar='z';
    
    for(int i=0;i<l;i++){
        maxChar=max(maxChar,s[i]);
        minChar=min(minChar,s[i]);
        if(i==0) {
            Node* rootNode=getnewNode(s[0]);
            head=rootNode;
        }
        else{
        Node* temp=head;
        // cout<<(*temp).data<<" ";
        while((*temp).next!=NULL){
            Node* temp2=temp;   //copy of temp before it is updated.
            cout<<(*temp).data<<" *";
            temp=(*temp).next;
            // if((*temp).data==s[i]){
            //     (*temp2).next=(*temp).next;
            //     free(temp);
            //     break;
            // }
        }

        if((*temp).next==NULL){
            Node* newNode=getnewNode(s[i]);
            (*temp).next=newNode;
            cout<<(*temp).data;
        }

    //     else if(i!=0){
    //         int length=0;
    //         Node* temp3=head;
    //         while(temp3!=NULL){
    //             temp3=(*temp3).next;
    //             length++;
    //         }

    //         int count=0;
    //         temp3=head;
    //         while(count<length/2){
    //             temp3=(*temp3).next;
    //             count++;
    //         }

    //         Node* newNode=getnewNode(s[i]);

    //         if(length%2==0){
    //             (*newNode).next=(*temp3).next;
    //             (*temp3).next=newNode;
    //         }

    //         else{
    //             if(s[i]>(*temp3).data){
    //                 temp3=(*temp).next;
    //             }
    //             // else{
    //             // } 
    //             (*newNode).next=(*temp3).next;
    //             (*temp3).next=newNode;
    //         }
    //     }
    // }
    // Node* temp=head;
    // Node* min;
    // Node* max;
    // while(temp!=NULL){
    //     if((*temp).data==minChar){
    //         min=temp;
    //     }
    //     if((*temp).data==maxChar){
    //         max=temp;
    //     }
    //     temp=(*temp).next;
    // }
    // Node* newhead=(*min).next;
    
    // (*min).next=max;

    // Node* temp4=head;
    // while(temp4!=min){
    //     cout<<(*temp4).data<<" ";
    //     temp4=(*temp4).next;
    }
    }

}





int main()
{
    head=NULL;
    string str;
    cin>>str;
    printoutput(str);

    return 0;
}
