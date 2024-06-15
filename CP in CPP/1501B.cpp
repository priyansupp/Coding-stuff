#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--){
        long long int n;
        cin>>n;
        vector<long long int>lay(n);
        for(long long int i=0;i<n;i++){
            cin>>lay[i];
        }
        long long int x=INT_MAX;
        vector<long long int>drench(n+1,0);
        for(int i=n;i>0;i--){
            x=min(x,i-lay[i-1]);
            
            if(x<i) drench[i]=1;
        }
        for(long long int k=1;k<=n;k++) cout<<drench[k]<<" ";
        cout<<endl;
    }
}