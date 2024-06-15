#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s,res={};
    cin>>s;
    for(int i=0;i<s.length();i++){
        if(s[i]<='Z' && s[i]>='A') s[i]+=32;
    }
    for(int i=0;i<s.length();i++){
        if(s[i]!='a' && s[i]!='e' && s[i]!='i' && s[i]!='o' && s[i]!='u' && s[i]!='y') res=res+'.'+s[i];
    }
    cout<<res;
    return 0;
}
