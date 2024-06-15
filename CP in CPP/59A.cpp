

#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    int lower=0,upper=0;
    cin>>s;
    for(int i=0;i<s.length();i++){
        if(s[i]<='z' && s[i]>='a') lower++;
        else upper++;
    }
    if(lower>=upper){
        for(int i=0;i<s.length();i++){
            if(s[i]<='Z' && s[i]>='A'){
                s[i]=s[i]+32;
            }
        }
    }
    else{
        for(int i=0;i<s.length();i++){
            if(s[i]<='z' && s[i]>='a'){
                s[i]=s[i]-32;
            }
        }
    }
    cout<<s;

}
