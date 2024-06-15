#include<bits\stdc++.h>
using namespace std;

int countoccurrence(int arr[], int n, int k){
    int t=n/k;
    sort(arr,arr+n);
    vector<int>countt;
    for(int i=0;i<n;i=upper_bound(arr,arr+n,arr[i])-arr){
        int x=count(arr,arr+n,arr[i]);
        if(x>t) countt.push_back(x);
    }
    return countt.size();
}
int main()
{
    int n,k;
    cin>>n>>k;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    cout<<countoccurrence(arr,n,k);  
}
