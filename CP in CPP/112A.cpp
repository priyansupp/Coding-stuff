#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s1,s2;
    cin>>s1>>s2;
    int c=0;
    for(int i=0;i<s1.length();i++){
        if(s1[i]<='Z' && s1[i]>='A') s1[i]+=32;
        if(s2[i]<='Z' && s2[i]>='A') s2[i]+=32;
    }
    for(int i=0;i<s1.length();i++){
        if(s1[i]<s2[i]){
            cout<<-1;
            c=1;
            break;
        }
        else if(s1[i]>s2[i]){
            cout<<1;
            c=1;
            break;
        }
    }
    if(c==0) cout<<0;
    return 0;
}

