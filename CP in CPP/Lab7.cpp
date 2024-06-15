#include <iostream>
#include <cmath>
#include <utility>
#include <string>
#include <algorithm>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <array>
#include <unordered_set>
#include <stack>
#include <unordered_map>
#include <deque>
#include <vector>
#include <iterator>
#include <cstdlib>
#include <bitset>
#include <numeric>
#include <fstream>
#include <sstream>

using namespace std;
using std::string;

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
    int date;
    string name;
    Node* next;
};

Node* head;

Node* getnewNode(string d, string n){
    Node* newNode= new Node();
    (*newNode).date=stoi(d);
    (*newNode).name=n;
    (*newNode).next=NULL;
    return newNode;
}

void bookres(string date, string name, int limit){
    if(head==NULL){
        Node* rootNode= getnewNode(date,name);
        head=rootNode;
    }
    else{
        Node* temp=head;
        vector<int>arr(31,0);
        int x;
        while((*temp).next!=NULL){
            x=(*temp).date;
            arr[x]++;
            temp=(*temp).next;
        }
        int t=stoi(date);
        if(arr[t]>=limit) cout<<"SORRY, QUOTA OVER"<<endl;
        else{
            Node* node=getnewNode(date,name);
            (*temp).next=node;
        }
    }
}

void changedate(string old, string name, string newdate){
    Node* temp=head;
    if(head==NULL) return;
    while((*temp).next!=NULL){
        if((*temp).date==stoi(old) && (*temp).name==name){
            (*temp).date=stoi(newdate);
            break;
        }
        temp=(*temp).next;
    }
    return;
}


void cancelbook(string date, string name){
    Node* temp=head;
    Node* addresstemp;
    Node* nexttemp;
    if(head==NULL) return;
    while(temp!=NULL){
        if((*temp).date==stoi(date) && (*temp).name==name){
            addresstemp=temp;
            nexttemp=(*temp).next;
            free(temp);
            break;
        }
        temp=(*temp).next;
    }
    temp=head;
    while(temp!=NULL){
        if((*temp).next==addresstemp){
            (*temp).next=nexttemp;
            break;
        }
        temp=(*temp).next;
    }
    return;
}

void printres(string date){
    Node* temp=head;
    cout<<date<<": ";
    int c=0;
    if(head==NULL) return;
    while(temp!=NULL){
        if((*temp).date==stoi(date)){
            cout<<(*temp).name<<" ";
            c=1;
        }
        temp=(*temp).next;
    }
    if(c==0) cout<<"NO GUESTS"<<endl;
    else cout<<endl;
}



int main()
{
    head=NULL;
    string line;
    ifstream File1;
    File1.open("amusement.dat");
    getline(File1, line);
    File1.close();
    stringstream ss;
    ss<<line;
    string temp;
    vector<string>input;
    while(!ss.eof()){
        ss>>temp;
        input.pb(temp);
        temp="";
    }

    int size=input.size();
    int limit=stoi(input[0]);
    for(int i=1;i<size;){
        switch(stoi(input[i])){
            case 1:
                bookres(input[i+1],input[i+2], limit);
                i=i+3;
                break;
            case 2:
                changedate(input[i+1],input[i+2],input[i+3]);
                i=i+4;
                break;
            case 3:
                cancelbook(input[i+1],input[i+2]);
                i=i+3;
                break;
            case 4: 
                printres(input[i+1]);
                i=i+2;
                break;
            case 5:
                return 0;
                break;
                
        }

    }
}