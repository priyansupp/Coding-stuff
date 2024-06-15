/*
NAME    :  PRIYANSHU JAISWAL
Roll.No :  200123043
LAB No. :  8
LAB Grp :  1
*/


#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;i++)
typedef vector<int> vi;


struct Node{
    Node * parnt;
    int key;
    Node * left;
    Node * mid;
    Node * right;
};
#define ll long long
#define mp make_pair 
#define ff first
#define ss second
#define ull unsigned long long
#define pll pair <ll,ll>
#define vpll vector <pair <ll, ll > >
#define pyes cout<<"Yes"<<endl
#define pno cout<<"No"<<endl
#define pcyes cout<<"YES"<<endl
#define pq priority_queue

Node* make_Node(int x){
    Node* nde = new Node();
    nde->key =x;
      nde->parnt =  nde->left = nde->mid =  nde->right = NULL;
    return nde;
}

bool search_tree(Node* root, int key);

vi leaves;
Node* root;

void Build(){
    vector<vector<Node*>> container;
    sort(leaves.begin(),leaves.end());
    vector<Node*> val;
    rep(i,0,leaves.size()){
        val.push_back(make_Node(leaves[i]));
    }
    container.push_back(val);
    while(container[container.size()-1].size()>=2){
        val.clear();
        if(container[container.size()-1].size()%3==0)
        {
            rep(i,0,container[container.size()-1].size()/3)
            {
                Node*t = make_Node(container[container.size()-1][3*i+2]->key);
                t->left = container[container.size()-1][3*i];    t->left->parnt = t;
                t->mid = container[container.size()-1][3*i+1];  t->mid->parnt = t;
                t->right = container[container.size()-1][3*i+2];  t->right->parnt = t;
                val.push_back(t);
            }
            
        }
        if(container[container.size()-1].size()%3==1)
        {
            rep(i,0,(container[container.size()-1].size()-4)/3){
                Node*t = make_Node(container[container.size()-1][3*i+2]->key);
                t->left = container[container.size()-1][3*i+0];  t->left->parnt = t;
                t->mid = container[container.size()-1][3*i+1];  t->mid->parnt = t;
                t->right = container[container.size()-1][3*i+2];  t->right->parnt = t;
                val.push_back(t);
            }
            int previous = container[container.size()-1].size() - 4;
            Node*t1 = make_Node(container[container.size()-1][previous+1]->key);
            t1->left = container[container.size()-1][previous+0];  t1->left->parnt = t1;
            t1->mid = container[container.size()-1][previous+1];  t1->mid->parnt = t1;
            val.push_back(t1);

            Node* t2 = make_Node(container[container.size()-1][previous+3]->key);
            t2->left = container[container.size()-1][previous+2];  t2->left->parnt = t2;
            t2->mid = container[container.size()-1][previous+3];  t2->mid->parnt = t2;
            val.push_back(t2);
            
        }
        if(container[container.size()-1].size()%3==2)
        {
            rep(i,0,(container[container.size()-1].size()-2)/3){
                Node*t = make_Node(container[container.size()-1][3*i+2]->key);
                t->left = container[container.size()-1][3*i+0];  t->left->parnt = t;
                t->mid = container[container.size()-1][3*i+1];  t->mid->parnt = t;
                t->right = container[container.size()-1][3*i+2];  t->right->parnt = t;
                val.push_back(t);
            }
            int previous = container[container.size()-1].size() - 2;
            Node*t1 = make_Node(container[container.size()-1][previous+1]->key);
            t1->left = container[container.size()-1][previous+0];  t1->left->parnt = t1;
            t1->mid = container[container.size()-1][previous+1];  t1->mid->parnt = t1;
            val.push_back(t1);
        }
        container.push_back(val);
    }
    
    for(int i=container.size()-1;i>-1;i--){
        rep(j,0,container[i].size()){
            cout<<container[i][j]->key<<" ";
        }
        cout<<endl;
    }
    root = container[container.size()-1][0];
    return;
}

void insert_new_Node(int x){
    leaves.push_back(x);
    cout<<endl;
    Build();
}


void delete_Node(int x){
    leaves.erase(find (leaves.begin(), leaves.end(), x));
    cout<<endl;
    Build();
}

int main(){   
    int n,values;
    cout<<"Enter number of elements to be inserted in tree: ";
    cin>>n;
    cout<<endl;
    cout<<"Enter the elements: ";
    rep(i,0,n){
        cin>>values;
        leaves.push_back(values);
    }
    Build();

    while(1){
    char c;
      cout<<"Press S for Search, D for Deletion, I for Insertion."<<endl;
      cin>>c;
      if(c=='S'){
    cout<<"Enter number to search"<<endl;
    int p;
        cin>>p;
        search_tree(root,p) ? cout<<"Element is FOUND\n" : cout<<"Element is NOT FOUND\n";  
        cout<<endl;
    }
    else if(c=='I'){
        cout<<"Enter number to insert"<<endl;;
        int a;
        cin>>a;
        insert_new_Node(a);
        cout<<endl;
    }
    else{
        cout<<"Enter number to delete"<<endl;
        int x;
        cin>>x;
        delete_Node(x);
    }
    }
 
    return 0;
}

bool search_tree(Node* root, int key){
    auto it = find(leaves.begin(), leaves.end(), key);
    if(it!=leaves.end()) return true;
    return false;
}
