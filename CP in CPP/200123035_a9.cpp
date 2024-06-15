#include<bits/stdc++.h>
using namespace std;

struct Node{
    string codes;
    Node* l;
    Node* r;
    char c;
};


Node* get(char c);


Node* tree(int &ind);


Node* base;
string s;
unordered_map<char,string> m;

void code(Node* base, string t);

void codes(Node* base);


int main()
{
        base=NULL;
        string b;
        cin>>s>>b;
        int i=0;
        base=tree(i);
        code(base,"");
        codes(base);
    
        m.erase('*');

        string res="";
        int pos=0;
        while(b.length()!=0){
            for(auto it: m){
                if(it.second == b.substr(pos, it.second.length())){
                pos+=it.second.length();
                if(b.length()-it.second.length()!=0){
                    b = b.substr(pos, b.length()-it.second.length());
                }
                else b="";
                res+=it.first;
                pos =0;
                break;
            }
            }
        }
        cout<<res<<endl;
    return 0;

}


Node* get(char data){
    Node* n= new Node();
    (*n).c=data;
    (*n).l=NULL;
    (*n).r=NULL;
    (*n).codes="";
    return n;
}

void code(Node* base, string t){
    if(base==NULL) return;
    (*base).codes+=t;
    code((*base).l,(*base).codes+"0");
    code((*base).r,(*base).codes+"1");
}

void codes(Node* base){
    if(base==NULL) return;
    m.insert({(*base).c,(*base).codes});
    codes((*base).l);
    codes((*base).r);
}


Node* tree(int &ind){
    if(ind==s.length()){
        return nullptr;
    }
    Node* node=get(s[ind]);
    ind++;
    if(s[ind-1]=='*'){
        (*node).l=tree(ind);
        (*node).r=tree(ind);
    }
    return node;
}
