#include<bits/stdc++.h>
using namespace std;
void lapindrome(string s){
    int l=s.length(), a=0;
    if(l%2==0){
        sort(s.begin(), s.begin()+l/2);
        sort(s.begin()+l/2,s.end());
        for(int i=0;i<l/2;i++){
            if(s[i]!=s[l/2+i])
                a=1;
        }
    }
    else{
        sort(s.begin(), s.begin()+(l/2));
        sort(s.begin()+(l/2+1),s.end());
        for(int i=0;i<l/2;i++){
            if(s[i]!=s[l/2+1+i])
                a=1;
        }
    }
    if(a==1)
        cout<<"NO"<<endl;
    else
        cout<<"YES"<<endl;
}
int main()
{
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        lapindrome(str);
    }
    return 0;
}
