#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        int ac=0, b=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='A' || s[i]=='C') ac++;
            else b++;
        }
        if(ac==b) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
