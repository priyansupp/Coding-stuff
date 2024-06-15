#include<bits\stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        string s;
        cin>>n>>s;
        int a=0,b=0,c=0;
        for(int i=0;i<s.length();i++){
                a=0;
                b=0;
            for(int j=i;j<s.length();j++){
                if(s[j]=='a') a++;
                else b++;
                if(a==b){
                cout<<i+1<<" "<<j+1<<endl;
                c=1;
                break;
                }
            }
            if(c==1) break;
        }
        if(c==0) cout<<-1<<" "<<-1<<endl;
    }
    return 0;
}
