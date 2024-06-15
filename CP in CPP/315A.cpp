#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,c=0;
    cin>>n;
    pair<int,int>arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i].first>>arr[i].second;
    }
    set<int>st;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i!=j && arr[i].first==arr[j].second){
                c++;
                break;
            }
        }
    }
    cout<<n-c;
    return 0;
}

