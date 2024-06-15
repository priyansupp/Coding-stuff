#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,t;
    string s;
    cin>>n>>t>>s;
    vector<int>vect;
    while(t--){
    for(int i=0;i<n;i++)
        if(s[i]=='B' && i+1<n && s[i+1]=='G') vect.push_back(i);

    for(int k=0;k<vect.size();k++) swap(s[vect[k]],s[vect[k]+1]);
    vect={};
    }
    cout<<s;

}

