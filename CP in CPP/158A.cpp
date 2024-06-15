#include<bits\stdc++.h>
using namespace std;
int main()
{
    int n,k,c=0,t;
    cin>>n>>k;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    t=arr[k-1];
    reverse(arr,arr+n);
    int ind=lower_bound(arr,arr+n,t)-arr;
    for(int i=ind;i<n;i++){
        if(arr[i]!=0) c++;
    }
    cout<<c<<endl;
}
