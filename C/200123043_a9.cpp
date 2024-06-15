#include<bits/stdc++.h>
using namespace std;

struct Node{
    char c;
    Node* left;
    Node* right;
    string p;
};

Node* root;

Node* getnewNode(char c){
    Node* newNode= new Node();
    (*newNode).c=c;
    (*newNode).left=NULL;
    (*newNode).right=NULL;
    (*newNode).p="";
    return newNode;
}

string s;

Node* maketree(int &index){
    if(index==s.length()){
        return nullptr;
    }
    Node* newNode=getnewNode(s[index]);
    if(s[index]=='*'){
        (*newNode).left=maketree(++index);
        (*newNode).right=maketree(++index);
    }
    return newNode;
}


void coding(Node* root, string t){
    if(root==NULL) return;
    (*root).p+=t;
    coding((*root).left,(*root).p+"0");
    coding((*root).right,(*root).p+"1");
}

map<char,string> mp;
void getcodes(Node* root){
    if(root==NULL) return;
    mp.insert({(*root).c,(*root).p});
    getcodes((*root).left);
    getcodes((*root).right);
}


int main()
{
     while(1){
        root=NULL;
        cout<<"Enter the preorder traversal of tree: ";
        getline(cin,s);

        string message;
        cout<<"Enter the encoded message: ";
        cin>>message;
        
        int ind=0;
        root=maketree(ind);
        coding(root,"");
        getcodes(root);
        
        string ans="";
        int position=0;
        while(message!=""){
            for(auto it: mp){
                if(it.first=='*') continue;
                if(it.second == message.substr(position, it.second.length())){
                position+=it.second.length();
                if(message.length()-it.second.length()!=0){
                    message = message.substr(position, message.length()-it.second.length());
                }else{
                    message="";
                }
                ans+=it.first;
                position =0;
                break;
            }
            }
        }
        cout<<ans<<endl;

    }
    return 0;

}