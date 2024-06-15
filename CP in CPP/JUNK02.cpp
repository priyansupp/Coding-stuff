#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n,c=0;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
            if(arr[i]%2==0){
                arr[i]=0;
            }
        }
        if(n%2==0){
            cout<<"No"<<endl;
            c=1;
        }
        if(c==0){
            if(arr[0]==0 || arr[n-1]==0) cout<<"No"<<endl;
            else cout<<"Yes"<<endl;
        }
    }
    return 0;
}
