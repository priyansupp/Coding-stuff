#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    int n,temp=0;
    cin>>n>>s;
    for(int i=0;i<n;i++)
        if(s[i]==s[i+1] && i+1<n) temp++;

    cout<<temp;
    return 0;
}
