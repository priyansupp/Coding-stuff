#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    int n=0;
    cin>>s;
    for(int i=0;i<s.length();i++){
        if(s[i]=='4' || s[i]=='7') n++;
    }
    if(n==4 || n==7) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}
