#include<bits\stdc++.h>
using namespace std;

int main()
{
    long long n,m;
    cin>>n>>m;
//    pair<int,int>arr[m];
//    for(int i=0;i<m;i++){
//        cin>>arr[i].first>>arr[i].second;
//    }
    int arr[m][2];
    for(int i=0;i<m;i++){
        for(int j=0;j<2;j++){
            cin>>arr[i][j];
        }
    }
    unordered_set< <int,int> >ust;
    for(int i=0;i<m;i++){
        for(int y=1;y<=n;y++){
            ust.insert({arr[i][0],y});
        }
        for(int x=1;x<=n;x++){
            ust.insert({x,arr[i][1]});
        }
        cout<<n*n-ust.size()<<" ";
    }
    return 0;
}
