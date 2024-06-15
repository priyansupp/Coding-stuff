#include<bits/stdc++.h>
using namespace std;

bool Pairexp(char c, char top){
    if(c==')') 
        return top=='(';
    else if(c=='}') 
        return top=='{';
    else 
        return top=='[';
}

bool balancedparanth(string s)
{
    string exp="";
    for(int i=0;i<s.length();i++){
        if(s[i]=='(' || s[i]=='{' || s[i]=='[' || s[i]==')' || s[i]=='}' || s[i]==']'){
            exp+=s[i];
        }
    }
    stack<char>S;
    for(int i=0;i<exp.length();i++){
        if(exp[i]=='(' || exp[i]=='{' || exp[i]=='['){
                S.push(exp[i]);
        }
        else{
            if(!S.empty() && Pairexp(exp[i], S.top())){
                S.pop();
            }
            else{
                return false;
            }
        }
    }
    return (S.empty()?true:false);
}

int  main()
{
    string s;
    cin>>s;
    //cout<<(balancedparanth(s)?"Balanced":"Not Balanced")<<endl;
    balancedparanth(s)?cout<<"Balanced":cout<<"Not Balanced";     //both type of giving output works.
    return 0;
}
